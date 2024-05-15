cmake_minimum_required(VERSION 3.20.1)
project(glacier LANGUAGES CXX VERSION 0.1.0)
cmake_policy(SET CMP0016 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

add_executable(${PROJECT_NAME}
  src/glacier.cpp
)

add_subdirectory(
  Compiler/
)
