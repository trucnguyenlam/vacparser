#cmake_minimum_required(VERSION 3.7)
cmake_minimum_required(VERSION 3.5)
project(vacparser)

set(CMAKE_CXX_STANDARD 11)  # enable C++11 standard

set(SOURCE_FILES
        src/Tokens.cpp
        src/Lexer.cpp
        src/main.cpp
)

include_directories( ${PROJECT_SOURCE_DIR}/src)

add_executable(vacparser ${SOURCE_FILES})

install (TARGETS vacparser DESTINATION bin)
