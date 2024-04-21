add_subdirectory(calcuator_lib)

add_executable(output main.cc)

target_link_libraries(output
    PUBLIC
        calculator_lib
)