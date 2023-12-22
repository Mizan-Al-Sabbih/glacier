#pragma once

#include <string>
#include <string_view>

#define TOKEN_TYPES                                                            \
  TOKEN(LParen)                                                                \
  TOKEN(RParen)                                                                \
  TOKEN(LBrace)                                                                \
  TOKEN(RBrace)                                                                \
  TOKEN(LBoxedBrace)                                                           \
  TOKEN(RBoxedBrace)                                                           \
  TOKEN(Comma)                                                                 \
  TOKEN(Dot)                                                                   \
  TOKEN(Colon)                                                                 \
  TOKEN(Semicolon)                                                             \
  TOKEN(QuestionMark)                                                          \
  TOKEN(Plus)                                                                  \
  TOKEN(Dot)                                                                   \
  TOKEN(Colon)                                                                 \
  TOKEN(ColonColon)
TOKEN(KW_true)
TOKEN(KW_false)
TOKEN(KW_if)
TOKEN(KW_else)
TOKEN(KW_while)
TOKEN(KW_for)
TOKEN(KW_return)
TOKEN(KW_break)
TOKEN(KW_continue)
TOKEN(KW_switch)
TOKEN(KW_case)
TOKEN(KW_default)
TOKEN(KW_var)
TOKEN(KW_let)
TOKEN(KW_func)
TOKEN(KW_void)
TOKEN(KW_u8)
TOKEN(KW_u16)
TOKEN(KW_u32)
TOKEN(KW_u64)
TOKEN(KW_u128)
TOKEN(KW_usize)
TOKEN(KW_i8)
TOKEN(KW_i16)
TOKEN(KW_i32)
TOKEN(KW_i64)
TOKEN(KW_i128)
TOKEN(KW_isize)
TOKEN(KW_f32)
TOKEN(KW_f64)
TOKEN(KW_struct)
TOKEN(KW_enum)
TOKEN(KW_class)
TOKEN(KW_import)
TOKEN(KW_public)
TOKEN(KW_private)
TOKEN(KW_guard)
TOKEN(KW_self)
TOKEN(KW_super)
TOKEN(KW_override)
TOKEN(Newline)
TOKEN(Number)
TOKEN(Identifier)
TOKEN(Unknown)
TOKEN(Eof)

enum class TokenType {
#define TOKEN(x) x
  TOKEN_TYPES
#undef TOKEN
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
#define TOKEN(x) \
      case TokenType::x: \
      return #x;\
      TOKEN_TYPES
#undef TOKEN
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

  char peek(int offset = 0) {
    if (position.index + offset < contentLength()) {
      return content[position.index + offset];
    }
    return endOfFileChar;
  }

  void consume();

private:
  std::string_view &content;
  char currentChar = content[position.index];
};