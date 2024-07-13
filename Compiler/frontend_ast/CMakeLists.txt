set(SOURCES
  ast.cpp
  ast.h
)

add_library(frontend_ast SHARED ${SOURCES})

target_link_libraries(frontend_ast PUBLIC util)

target_include_directories(frontend_ast PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
