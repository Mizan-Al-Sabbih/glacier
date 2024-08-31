#include "lexer.h"
#include "utility.h"

bool Lexer::is_whitespace(char ch) { return ch == ' ' || '\t' || '\n'; }

const std::unordered_map<std::string, TokenType> Lexer::keywords = {
    {"var", TokenType::K_Variable},    {"let", TokenType::K_Let},
    {"func", TokenType::K_Function},   {"if", TokenType::K_If},
    {"else", TokenType::K_Else},       {"for", TokenType::K_For},
    {"while", TokenType::K_While},     {"return", TokenType::K_Return},
    {"break", TokenType::K_Break},     {"continue", TokenType::K_Continue},
    {"switch", TokenType::K_Switch},   {"case", TokenType::K_Case},
    {"default", TokenType::K_Default}, {"struct", TokenType::K_Struct},
    {"class", TokenType::K_Class},     {"enum", TokenType::K_Enum},
    {"import", TokenType::K_Import},   {"true", TokenType::K_True},
    {"false", TokenType::K_False},     {"none", TokenType::K_None},
    {"super", TokenType::K_Super},     {"self", TokenType::K_Self},
    {"String", TokenType::K_String},   {"Int", TokenType::K_Integer},
    {"Float", TokenType::K_Float},     {"Bool", TokenType::K_Boolean},
};

char Lexer::peak(int offset) const {
  if (index + offset < content.length()) {
    return content.at(index + offset);
  }
  return {};
}

char Lexer::consume(int offset) {
  char current_char = {};
  if (index < content.length()) {
    current_char = content.at(index);
    index += offset;
  }
  return current_char;
}

TokenType Lexer::get_keyword(const std::string &value) const {
  auto iter = keywords.find(value);
  if (iter != keywords.end()) {
    return iter->second;
  } else {
    return TokenType::Identifier;
  }
}

TokenType Lexer::get_punctuator(const char &value) {}

std::vector<Token> Lexer::analyze() {
  std::vector<Token> tokens;
  auto emit_token = [&](TokenType type, Span span) {
    tokens.push_back({type, span});
  };

  while (index < content.size()) {
    char ch = content.at(index);
    TokenType curr_type{TokenType::Unknown};

    if (is_whitespace(ch)) {
      consume();
      continue;
    }

    unsigned int start = index;

    switch (ch) {
    case '=':
      curr_type = TokenType::Equals;
      consume();
      break;
    case '(':
      curr_type = TokenType::LeftParen;
      consume();
      break;
    case ')':
      curr_type = TokenType::RightParen;
      consume();
      break;
    case '{':
      curr_type = TokenType::LeftBrace;
      consume();
      break;
    case '}':
      curr_type = TokenType::RightBrace;
      consume();
      break;
    case '[':
      curr_type = TokenType::LeftBracket;
      consume();
      break;
    case ']':
      curr_type = TokenType::RightBracket;
      consume();
      break;
    case ',':
      curr_type = TokenType::Comma;
      consume();
      break;
    case '.':
      curr_type = TokenType::Dot;
      consume();
      break;
    default:
      break;
    }

    if (ch == '\"') {
      while (peak(1) != '\"') {
        consume();
      }
      curr_type = TokenType::String;
    }
    if (isalpha(ch) || ch == '_') {
      std::string value;
      value += consume();
      while (isalnum(peak()) || peak() == '_') {
        value += consume();
      }
      curr_type = get_keyword(value);
    } else if (isdigit(ch) || ch == '-') {
      std::string value;
      value += consume();
      while (isdigit(peak()) || peak() == '.') {
        value += consume();
      }
      // Handle number parsing errors or special cases if needed
      curr_type = TokenType::Integer;
    }

    unsigned int end = index;
    emit_token(curr_type, {start, end});
  }

  if (index == content.size()) {
    emit_token(TokenType::Eof, {index, index});
  }

  return tokens;
}
