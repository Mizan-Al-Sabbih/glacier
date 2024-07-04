cmake_minimum_required(VERSION 3.20.1)
project(Glacier LANGUAGES CXX VERSION 0.1.0)
cmake_policy(SET CMP0016 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)

add_subdirectory(Compiler/)

add_executable(glacier src/glacier.cpp)

target_link_libraries(glacier PUBLIC
  compiler_lib
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

