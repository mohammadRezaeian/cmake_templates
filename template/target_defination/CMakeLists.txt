add_executable(learning main.cc)

# add_definitions(-DMESSAGE_FROM_OUTSIDE=\\"GHASEM\\")

target_compile_definitions(learning
    PUBLIC
     MESSAGE_FROM_OUTSIDE=\"hello\ Mohammad\"
)