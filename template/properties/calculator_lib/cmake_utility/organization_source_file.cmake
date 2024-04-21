file(GLOB source_files 
        src/*.cpp
        src/*.cc
)
file(GLOB headers_file_private 
        include/private/calculator_lib/*.h
)
file(GLOB headers_file_public
        include/public/calculator_lib/*.h
)
source_group("Source Files"
    FILES
        ${source_files}
)
source_group("Private Headers"
    FILES
        ${headers_file_private}
)
source_group("headers_file_public"
    FILES
        ${headers_file_public}
)
