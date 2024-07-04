set(LEXER_SOURCES
  lexer.cpp
  lexer.h
)

add_library(frontend_lexer SHARED ${LEXER_SOURCES})

target_include_directories(frontend_lexer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
