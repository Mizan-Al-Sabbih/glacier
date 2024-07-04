set(AST_SOURCES
  ast.cpp
  ast.h
)

add_library(frontend_ast SHARED ${AST_SOURCES})

target_include_directories(frontend_ast PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
