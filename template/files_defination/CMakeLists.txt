cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(manageCmakeUseFiles
    VERSION 1.0
    LANGUAGES CXX
)

add_subdirectory(calculator_lib)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        calculator_lib
)
