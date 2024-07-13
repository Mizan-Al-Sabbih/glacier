set(SOURCES
  lexer.cpp
  lexer.h
)

add_library(frontend_lexer SHARED ${SOURCES})

target_link_libraries(frontend_lexer PUBLIC util)

target_include_directories(frontend_lexer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
