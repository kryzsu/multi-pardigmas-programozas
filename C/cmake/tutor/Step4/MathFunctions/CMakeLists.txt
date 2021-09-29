project(MathFunctions C)

add_library(MathFunctions mysqrt.c)

# We first state that anybody linking to MathFunctions needs to include the current source directory
# INTERFACE means things that consumers require but the producer doesn't.
target_include_directories(MathFunctions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )