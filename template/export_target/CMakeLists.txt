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
    # add_subdirectory(calculator_lib)
    find_package(calculator_lib REQUIRED)
    list(APPEND extenral_libraries calculator_lib)
endif()

# cho '#cmakedefine enable_use_calculator_lib' > config.hh.in
configure_file(config.hh.in ${CMAKE_CURRENT_SOURCE_DIR}/config.hh)
add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${extenral_libraries}
)


#installation

install(TARGETS ${PROJECT_NAME})



#unistallation
# if(NOT EXISTS "${CMAKE_BINARY_DIR}/install_manifest.txt")
#     message(FATAL_ERROR "can't find it")
# endif()

# file(READ "${CMAKE_BINARY_DIR}/install_manifest.txt" files)
# string(REGEX REPLACE "\n" ";" files "${files}")

# message("${files}")

# foreach(file ${files})
#     execute_process(
#         COMMAND ${CMAKE_COMMAND} -E rm -r ${file}
#         RESULT_VARIABLE return_code
#     )

#     if(NOT "${return_code}" STREQUAL 0)
#         message(FATAL_ERROR "Couldn't remove ${file}")
#     endif()
# endforeach()

# set (CPACK_PACKAGE_CONTACT "F")
include(InstallRequiredSystemLibraries)
include(CPack)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
