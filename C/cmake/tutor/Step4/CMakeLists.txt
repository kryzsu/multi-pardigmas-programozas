cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial
        VERSION 3.0
        DESCRIPTION desc
        LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE on)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

message(STATUS "USE_MYMATH ${USE_MYMATH}")
if (USE_MYMATH)
    # add the MathFunctions library
    add_subdirectory(MathFunctions)
endif()

# add the executable
add_executable(Tutorial tutorial.c)



if (USE_MYMATH)
    target_link_libraries(Tutorial PUBLIC MathFunctions)
else()
    target_link_libraries(Tutorial PUBLIC m)
endif()

configure_file(TutorialConfig.h.in TutorialConfig.h)

message(STATUS "${EXTRA_INCLUDES}")

target_include_directories(Tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        )
