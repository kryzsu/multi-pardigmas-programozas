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
    message(STATUS "mymath")
    target_link_libraries(Tutorial PUBLIC MathFunctions)
else()
    message(STATUS "libmath")
    target_link_libraries(Tutorial PUBLIC m)
endif()

configure_file(TutorialConfig.h.in TutorialConfig.h)

message(STATUS "${EXTRA_INCLUDES}")

target_include_directories(Tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

enable_testing()

# does the application run
add_test(NAME Runs COMMAND Tutorial 25)


# define a function to simplify adding tests
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result}
            )
endfunction(do_test)

do_test(Tutorial 4 "result 4.0")
do_test(Tutorial 2 "result 2.0")

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include
        )