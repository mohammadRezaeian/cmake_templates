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
option(enable_use_calculator_lib "Do you want use CalculatorLibrary?" on)

if(enable_use_calculator_lib)
    add_subdirectory(calculator_lib)
    list(APPEND extenral_libraries calculator_lib)
endif()

# cho '#cmakedefine enable_use_calculator_lib' > config.hh.in
configure_file(config.hh.in ${CMAKE_CURRENT_SOURCE_DIR}/config.hh)
add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${extenral_libraries}
)


if(NOT TARGET uninstall)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake_unistall_role.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/cmake_unistall_role.cmake
        IMMEDIATE @ONLY
    )

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND}
    -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_unistall_role.cmake )

endif()

#installation

install(TARGETS ${PROJECT_NAME})
