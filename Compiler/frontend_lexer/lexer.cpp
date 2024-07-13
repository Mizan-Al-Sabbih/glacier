#include "lexer.h"

bool Lexer::is_whitespace(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n';
}

char Lexer::peak(int offset) const {
  if (index + offset < content.length()) {
    return content.at(index + offset);
  }
  return {};
}

char Lexer::consume(int offset) {
  char current_char = '\0';
  if (index < content.length()) {
    current_char = content.at(index);
    index += offset;
  }
  return current_char;
}

TokenType Lexer::get_keyword(const std::string &value) const {
  auto iter = Token::keywords.find(value);
  if (iter != Token::keywords.end()) {
    return iter->second;
  } else {
    return TokenType::Identifier;
  }
}

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
