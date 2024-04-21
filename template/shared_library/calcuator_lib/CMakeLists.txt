add_library(calculator_lib
    SHARED
        include/calculator_lib/calculator.h
        src/calculator.cpp
)

target_include_directories(calculator_lib
    PUBLIC
        include/
)