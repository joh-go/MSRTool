cmake_minimum_required(VERSION 3.14)

project(MyProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler-Warnungen
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ---------- Hauptprogramm ----------
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(MSRTool ${SOURCES})

target_include_directories(MSRTool
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

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
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)

# Test-Executable erstellen
add_executable(UnitTests ${TEST_SOURCES})
target_include_directories(UnitTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(UnitTests PRIVATE gtest_main)

# Tests registrieren
include(GoogleTest)
gtest_discover_tests(UnitTests)