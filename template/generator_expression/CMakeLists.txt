cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(generator_expression
    LANGUAGES
    CXX
)


add_executable(generator_expression main.cpp)

# SET (COMPILER_NAME)
# if(MSVC)
#     set(COMPILER_NAME  "MSVC")
# else()
#     set(COMPILER_NAME "GNU")
# endif()

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        COMPILER_NAME="$<IF:$<BOOL:${MSVC}>, MSVC , GNU>"
)
