cmake_minimum_required(VERSION 3.28.0)
project(Template VERSION 0.0.1
                 DESCRIPTION "SFML C++ Project template"
                 LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Global settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR} CACHE PATH "Install path" FORCE)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

#########################################################################
# Check out of source directory
#########################################################################

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

#########################################################################
# Force a local install
#########################################################################
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

#########################################################################
# Dependencies 
#########################################################################
include(FetchContent)

set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_AUDIO   OFF CACHE BOOL "" FORCE)


FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

#########################################################################
# Sources
#########################################################################

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

#########################################################################
# Utils
#########################################################################
function(add_cxx_flags target)
    target_compile_options(${target} PRIVATE
        -Wall
        -Wextra
        -Wconversion
        -Wpedantic
    )
    set_property(TARGET ${target} APPEND PROPERTY POSITION_INDEPENDENT_CODE ON)
endfunction()

#########################################################################
# Executable
#########################################################################
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "src")
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

Add_Cxx_flags(${PROJECT_NAME})


#########################################################################
# Copy res directory to binary directory
#########################################################################

# add_custom_command(
#         TARGET ${PROJECT_NAME}
#         COMMENT "Copy Res directory"
#         PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
#         VERBATIM)


