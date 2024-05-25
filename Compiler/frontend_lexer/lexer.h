#pragma once

enum class TokenType {
  Plus,
  Minus,
  Asterisk,
  Slash,
  Dot,

  K_Variable,
  K_Function,
  K_If,

  Identifiers,

  Unknown,
  Eof
};

struct Span {
  unsigned int start = 0;
  unsigned int end = 0;
};

struct Token {
  TokenType type { TokenType::Unknown };
  Span span;
};

class Lexer {
public:
private:
};
