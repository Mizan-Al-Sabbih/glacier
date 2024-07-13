#pragma once

#include <vector>

#include "lexer.h"
#include "utility.h"

class Compiler {
private:
  struct Settings {
    bool no_colours = false;
    bool dump_tokens = false;
    bool dump_ast = false;
  };

public:
  Compiler(const std::string filepath) {
    Lexer lexer(filepath);
    m_tokens = lexer.analyze();
  };

  ~Compiler() = default;

  void dump_tokens() {
    if (settings.dump_tokens == false)
      return;
    for (auto token : m_tokens) {
      if (settings.no_colours == false) {
      }
      std::cout << "TokenType::" << token.type_to_string() << '\n';
    }
  }

  // TokenType parse() {}

private:
  Settings settings;
  std::vector<Token> m_tokens;
};
