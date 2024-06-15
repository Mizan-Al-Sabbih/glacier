add_library(frontend_lexer SHARED
  frontend_lexer/lexer.cpp
  frontend_lexer/lexer.h
)

target_include_directories(frontend_lexer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/frontend_lexer
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(frontend_ast SHARED
  frontend_ast/ast.cpp
  frontend_ast/ast.h
)

target_include_directories(frontend_ast PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/frontend_ast
  ${CMAKE_CURRENT_SOURCE_DIR}
)
