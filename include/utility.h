#pragma once

#include <string>
#include <string_view>

enum class TokenType {
  // Single-character tokens
  LParen,
  RParen,
  LBrace,
  RBrace,
  LBoxedBrace,
  RBoxedBrace,

  // Punctuations
  Comma,
  Dot,
  Colon,
  ColonColon,

  // Keywords
  KW_true,
  KW_false,
  KW_if,
  KW_else,
  KW_while,
  KW_for,
  KW_return,
  KW_break,
  KW_continue,
  KW_switch,
  KW_case,
  KW_default,
  KW_var,
  KW_let,
  KW_func,
  KW_u8,
  KW_u16,
  KW_u32,
  KW_u64,
  KW_u128,
  KW_usize,
  KW_i8,
  KW_i16,
  KW_i32,
  KW_i64,
  KW_i128,
  KW_isize,
  KW_f32,
  KW_f64,
  KW_struct,
  KW_enum,
  KW_class,
  KW_import,
  KW_public,
  KW_private,
  KW_guard,
  KW_self,

  Newline,
  Identifier,

  Unknown,
  Eof
};

struct Position {
  size_t index = 0u;
  size_t line = 1u;
  size_t column = 1u;
};

struct Token {
  TokenType type { TokenType::Unknown };
  std::string lexeme = "";
  Position position;

  Token(TokenType type, std::string_view lexeme, Position position)
      : type(type), lexeme(lexeme), position(position){};

  std::string toString() const {
    switch (type) {
    case TokenType::LParen:
      return "LeftParen";
    case TokenType::RParen:
      return "RightParen";
    case TokenType::LBrace:
      return "LeftBrace";
    case TokenType::RBrace:
      return "RightBrace";
    case TokenType::LBoxedBrace:
      return "LeftBoxedBrace";
    case TokenType::RBoxedBrace:
      return "RBoxedBrace";
    case TokenType::Newline:
      return "Newline";
    case TokenType::Identifier:
      return "Identifier";
    default:
      return "Unknown";
    }
  }
};

class Cursor {
public:
  Position position;
  char endOfFileChar = '\0';

  explicit Cursor(std::string_view &content) : content(content){};

  unsigned int contentLength() const { return content.length(); }

  char peek() {
    if (position.index < contentLength()) {
      if (currentChar == '\n') {
        position.line++;
        position.column = 1u;
      }
      return currentChar;
    }
    return position.index >= contentLength() ? '\0' : currentChar;
  }

  char consume();

private:
  std::string_view &content;
  char currentChar = content[position.index];
};