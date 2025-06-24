cmake_minimum_required(VERSION 3.31)
project(BitwiseCommandLineToolkit)

set(CMAKE_CXX_STANDARD 20)

# Include all subdirectories containing headers
include_directories(
        ${PROJECT_SOURCE_DIR}/BitwiseOperations
        ${PROJECT_SOURCE_DIR}/CommandParser
        ${PROJECT_SOURCE_DIR}/core
)

# Define source files
set(SOURCES
        main.cpp
        BitwiseOperations/bitwise_operations.cpp
        CommandParser/command_parser.cpp
        core/utils.cpp
)

# Define header files (optional for IDEs like CLion)
set(HEADERS
        BitwiseOperations/bitwise_operations.h
        CommandParser/command_parser.h
        core/utils.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
