#pragma once

#include <string>
#include <unordered_map>

#define TOKENS                                                                 \
  TOKEN(Plus)                                                                  \
  TOKEN(Minus)                                                                 \
  TOKEN(Asterisk)                                                              \
  TOKEN(Slash)                                                                 \
  TOKEN(GreaterThan)                                                           \
  TOKEN(LessThan)                                                              \
  TOKEN(Dot)                                                                   \
  TOKEN(Comma)                                                                 \
  TOKEN(Equals)                                                                \
  TOKEN(DoubleEquals)                                                          \
  TOKEN(LeftParen)                                                             \
  TOKEN(RightParen)                                                            \
  TOKEN(LeftBrace)                                                             \
  TOKEN(RightBrace)                                                            \
  TOKEN(LeftBracket)                                                           \
  TOKEN(RightBracket)                                                          \
  TOKEN(Integer)                                                               \
  TOKEN(String)                                                                \
  TOKEN(K_Variable)                                                            \
  TOKEN(K_Let)                                                                 \
  TOKEN(K_Function)                                                            \
  TOKEN(K_If)                                                                  \
  TOKEN(K_Else)                                                                \
  TOKEN(K_For)                                                                 \
  TOKEN(K_While)                                                               \
  TOKEN(K_Return)                                                              \
  TOKEN(K_Break)                                                               \
  TOKEN(K_Continue)                                                            \
  TOKEN(K_Switch)                                                              \
  TOKEN(K_Case)                                                                \
  TOKEN(K_Default)                                                             \
  TOKEN(K_Struct)                                                              \
  TOKEN(K_Class)                                                               \
  TOKEN(K_Enum)                                                                \
  TOKEN(K_Import)                                                              \
  TOKEN(K_True)                                                                \
  TOKEN(K_False)                                                               \
  TOKEN(K_None)                                                                \
  TOKEN(K_Super)                                                               \
  TOKEN(K_Self)                                                                \
  TOKEN(K_String)                                                              \
  TOKEN(K_Integer)                                                             \
  TOKEN(K_Float)                                                               \
  TOKEN(K_Boolean)                                                             \
  TOKEN(Identifier)                                                            \
  TOKEN(Unknown)                                                               \
  TOKEN(Eof)

enum class TokenType {
#define TOKEN(x) x,
  TOKENS
#undef TOKEN
};

struct Span {
  unsigned int start = 0;
  unsigned int end = 0;

  auto length() const { return (end - start) + 1; }
};

struct Token {
  TokenType type{TokenType::Unknown};
  Span span;

  std::string type_to_string() const {
    switch (type) {
#define TOKEN(x)                                                               \
  case TokenType::x:                                                           \
    return #x;
      TOKENS
#undef TOKEN
    }
  }

  static const std::unordered_map<std::string, TokenType> keywords;
};
