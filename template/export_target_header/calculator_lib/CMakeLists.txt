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
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/private/>
        $<INSTALL_INTERFACE:include>
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
        $<INSTALL_INTERFACE:include>
)
#installation

#export config
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config)
install(EXPORT ${PROJECT_NAME}Config  DESTINATION lib/cmake/${PROJECT_NAME})

install(FILES ${headers_file_public} DESTINATION include/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(
    FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)



# message(${headers_file})

# add_library(calculator_lib
#     SHARED
#         include/private/calculator_lib/core.h
#         include/public/calculator_lib/calculator.h
#         src/calculator.cpp
#         src/core.cc
# )
