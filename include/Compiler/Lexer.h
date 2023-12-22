#pragma once

#include <vector>
#include <string_view>
#include <utility.h>

#define DEBUG_MODE 1

class Lexer {
public:
  explicit Lexer(std::string_view&);
  std::vector<Token> tokenize();

private:
  Cursor cursor;
};