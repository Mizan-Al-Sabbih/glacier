cmake_minimum_required(VERSION 3.20.1)
project(Glacier LANGUAGES CXX VERSION 0.1.0)
cmake_policy(SET CMP0016 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(
  Compiler/
)

add_executable(glacier
  src/glacier.cpp
)

target_link_libraries(glacier PRIVATE frontend_lexer)
target_include_directories(glacier PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Compiler/frontend_lexer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
