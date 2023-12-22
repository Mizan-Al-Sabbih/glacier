#pragma once

#include <string_view>
#include <vector>
#include <utility.h>

class Lexer {
public:
  explicit Lexer(std::string_view&);
  std::vector<Token> tokenize();

private:
  Cursor cursor;
};