#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

namespace Compiler {

enum class TokenType {
  Plus,
  Minus,
  Asterisk,
  Slash,
  GreaterThan,
  LessThan,
  Dot,
  Comma,
  Equals,
  DoubleEquals,

  LeftParen,
  RightParen,
  LeftBrace,
  RightBrace,
  LeftBracket,
  RightBracket,

  Integer,
  String,

  K_Variable,
  K_Function,
  K_If,
  K_Else,
  K_While,
  K_For,
  K_Return,
  K_Break,
  K_Continue,
  K_Switch,
  K_Case,
  K_Default,
  K_True,
  K_False,
  K_None,
  K_And,
  K_Or,
  K_Not,
  K_NotEqual,
  K_Equal,
  K_Class,
  K_Super,
  K_Self,
  K_Struct,
  K_Enum,
  K_Import,
  K_String,
  K_Integer,
  K_Float,
  K_Boolean,

  Identifier,

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

}
