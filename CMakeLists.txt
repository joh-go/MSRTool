cmake_minimum_required(VERSION 3.14)

project(MSRTool VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliothek erstellen
# Header und Source-Dateien automatisch finden
file(GLOB_RECURSE LIB_HEADERS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(MSRTools
    ${LIB_SOURCES} ${LIB_HEADERS}
)

# Include-Verzeichnis öffentlich machen
target_include_directories(MSRTools
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

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

# Optional: Unit-Tests mit GoogleTest
enable_testing()
add_subdirectory(tests)
