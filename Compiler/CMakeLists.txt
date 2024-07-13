add_library(util INTERFACE
  utility.cpp
  utility.h
)
target_include_directories(util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(frontend_lexer/)
add_subdirectory(frontend_ast/)

set(Libs
  frontend_lexer
  frontend_ast
  util
)

set(SOURCES
  compiler.cpp
  compiler.h
  utility.h
)

add_library(compiler_lib SHARED
  ${SOURCES}
)

target_link_libraries(compiler_lib PUBLIC
  ${Libs}
)

target_include_directories(compiler_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

