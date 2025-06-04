# ---------- Tests mit GoogleTest ----------
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0 # oder aktuelle Version
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test-Dateien finden
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Test-Executable erstellen
add_executable(UnitTests ${TEST_SOURCES})
target_include_directories(UnitTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(UnitTests PRIVATE MSRTools gtest_main)

add_test(NAME UnitTests COMMAND UnitTests)

# Tests registrieren
include(GoogleTest)
gtest_discover_tests(UnitTests)