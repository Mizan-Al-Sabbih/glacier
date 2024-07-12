add_subdirectory(frontend_lexer/)
add_subdirectory(frontend_ast/)

set(SOURCES
  compiler.cpp
  compiler.h
)

add_library(compiler_lib SHARED
  ${SOURCES}
)

target_link_libraries(compiler_lib PUBLIC
  frontend_lexer
  frontend_ast
)

target_include_directories(compiler_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

