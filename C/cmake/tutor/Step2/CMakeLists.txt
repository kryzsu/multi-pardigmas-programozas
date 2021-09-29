cmake_minimum_required(VERSION 3.10)

set(CMAKE_VERBOSE_MAKEFILE on)
# add the MathFunctions library
add_subdirectory(MathFunctions)

# set the project name
project(Tutorial
        VERSION 2.0
        DESCRIPTION desc
        LANGUAGES C)
# add the executable
add_executable(Tutorial tutorial.c)

target_link_libraries(Tutorial PUBLIC MathFunctions)

configure_file(TutorialConfig.h.in TutorialConfig.h)

target_include_directories(Tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/MathFunctions"
        )
