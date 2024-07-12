#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "utility.h"

class Lexer {
public:
  explicit Lexer(std::string_view source) : content(source), index(0) {}

  std::vector<Token> analyze();

private:
  char peak(int offset = 0) const;

  char consume(int offset = 1);

  TokenType get_keyword(const std::string &value) const;

  static const std::unordered_map<std::string, TokenType> keywords;

  std::string_view content;
  unsigned int index;
};
