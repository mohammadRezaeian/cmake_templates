# file(GLOB source_files 
#         src/*.cpp
#         src/*.cc
# )

# file(GLOB headers_file_private 
#         include/private/calculator_lib/*.h
# )


# file(GLOB headers_file_public
#         include/public/calculator_lib/*.h
# )

# source_group("Source Files"
#     FILES
#         ${source_files}
# )

# source_group("Private Headers"
#     FILES
#         ${headers_file_private}
# )

# source_group("headers_file_public"
#     FILES
#         ${headers_file_public}
# )

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(calculator_lib
    VERSION 1.0
    LANGUAGES CXX
)


include(cmake_utility/organization_source_file.cmake)

add_library(${PROJECT_NAME}
    SHARED
        ${source_files}
        ${headers_file_private}
        ${headers_file_public}

)
#precompile headers
target_precompile_headers(${PROJECT_NAME}
    INTERFACE
        ${headers_file_public}

)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include/private/
    PUBLIC
        include/public
)
#installation
install(TARGETS ${PROJECT_NAME})
install(FILES ${headers_file_public} DESTINATION include)



#unistallation
if(NOT EXISTS "${CMAKE_BINARY_DIR}/install_manifest.txt")
    message(FATAL_ERROR "can't find it")
endif()

file(READ "${CMAKE_BINARY_DIR}/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "{files}")

foreach(file "${files}")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E rm -r ${file}
        RESULT_VARIABLE return_code
    )

    if(NOT "${return_code}" STREQUAL 0 )
        message(FATAL_ERROR "Couldn't remove ${file}")
    endif()
endforeach()


# message(${headers_file})

# add_library(calculator_lib
#     SHARED
#         include/private/calculator_lib/core.h
#         include/public/calculator_lib/calculator.h
#         src/calculator.cpp
#         src/core.cc
# )
