#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

#include "utility.h"

class Lexer {
public:
  explicit Lexer(const std::string filepath) {
    std::ifstream file(filepath);
    if (!file) {
      std::cerr << "Failed to open file: " << filepath << std::endl;
      exit(1);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    file.close();
  }

  std::vector<Token> analyze();

private:
  char peak(int offset = 0) const;

  char consume(int offset = 1);

  bool is_whitespace(char ch);

  TokenType get_keyword(const std::string &value) const;

  TokenType get_punctuator();

  std::string_view content;
  unsigned int index = 0;
};
