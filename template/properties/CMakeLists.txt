cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(ManageCmakeOptions
    VERSION 1.0
    LANGUAGES CXX
)

# add_subdirectory(calculator_lib)

# add_executable(${PROJECT_NAME} main.cc)

# target_link_libraries(${PROJECT_NAME}
#     PUBLIC
#         calculator_lib
# )


set(extenral_libraries)
option(enable_use_calculator_lib "Do you want use CalculatorLibrary?" off)
if(enable_use_calculator_lib)
    add_subdirectory(calculator_lib)
    list(APPEND extenral_libraries calculator_lib)
endif()

# cho '#cmakedefine enable_use_calculator_lib' > config.hh.in
configure_file(config.hh.in ${CMAKE_CURRENT_SOURCE_DIR}/config.hh)
add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${extenral_libraries}
)

set_target_properties(${PROJECT_NAME
    PROPERTIES
       CXX_STANDARD 17
       CXX_STANDARD_REQUIRED on # if it wasn't 17 show me error
       CXX_EXTENSIONS off #extension compiler
)

# or set for all
# set(CMAKE_CXX_STANDARD 17)
