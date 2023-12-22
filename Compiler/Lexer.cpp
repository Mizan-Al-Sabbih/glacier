#include <Compiler/Lexer.h>

Lexer::Lexer(std::string_view &content) : cursor(content) {}

std::vector<Token> Lexer::tokenize() {
  std::vector<Token> tokens;
  while (cursor.position.index < cursor.contentLength()) {
    auto currentChar = cursor.peek();
    if (currentChar == ' ' || currentChar == '\t' || currentChar == '\v' ||
        currentChar == '\f' || currentChar == '\r') {
      cursor.consume();
      continue;
    }
    if (currentChar == '/' && cursor.peek(1) == '/') {
      cursor.consume();
      cursor.consume();
      while (cursor.peek() != '\n' &&
             cursor.position.index < cursor.contentLength()) {
        cursor.consume();
      }
      cursor.consume();
      if (cursor.peek() == '\n') {
        cursor.position.line++;
        cursor.position.column = 0u;
      }
      continue;
    }
    if (currentChar == '/' && cursor.peek(1) == '*') {
      cursor.consume();
      cursor.consume();
      while (currentChar != '*' && cursor.peek(1) != '/' &&
             cursor.position.index < cursor.contentLength()) {
        if (cursor.peek() == '\n') {
          cursor.position.line++;
          cursor.position.column = 0u;
        }
        cursor.consume();
      }
      cursor.consume();
      cursor.consume();
      continue;
    }
    if (currentChar == '\n') {
      cursor.position.line++;
      cursor.position.column = 0u;
      tokens.push_back(Token(TokenType::Newline, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '(') {
      tokens.push_back(Token(TokenType::LParen, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ')') {
      tokens.push_back(Token(TokenType::RParen, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '{') {
      tokens.push_back(Token(TokenType::LBrace, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '}') {
      tokens.push_back(Token(TokenType::RBrace, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '[') {
      tokens.push_back(Token(TokenType::LBrace, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ']') {
      tokens.push_back(Token(TokenType::RBrace, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ',') {
      tokens.push_back(Token(TokenType::Comma, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '.') {
      tokens.push_back(Token(TokenType::Dot, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ':') {
      tokens.push_back(Token(TokenType::Colon, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ':' && cursor.peek(1) == ':') {
      cursor.consume();
      tokens.push_back(Token(TokenType::ColonColon, "", cursor.position));
      cursor.consume();
      continue;
    }
    if (isalpha(currentChar) || currentChar == '_') {
      std::string id = "";
      cursor.consume();
      while (isalnum(cursor.peek()) || cursor.peek() == '_') {
        id += currentChar;
        cursor.consume();
      }
      if (id == "true") {
        tokens.push_back(Token(TokenType::KW_true, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "false") {
        tokens.push_back(Token(TokenType::KW_false, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "if") {
        tokens.push_back(Token(TokenType::KW_if, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "else") {
        tokens.push_back(Token(TokenType::KW_else, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "while") {
        tokens.push_back(Token(TokenType::KW_while, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "for") {
        tokens.push_back(Token(TokenType::KW_for, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "var") {
        tokens.push_back(Token(TokenType::KW_var, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "let") {
        tokens.push_back(Token(TokenType::KW_let, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "func") {
        tokens.push_back(Token(TokenType::KW_func, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "return") {
        tokens.push_back(Token(TokenType::KW_return, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "break") {
        tokens.push_back(Token(TokenType::KW_break, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "continue") {
        tokens.push_back(Token(TokenType::KW_continue, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "switch") {
        tokens.push_back(Token(TokenType::KW_switch, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "case") {
        tokens.push_back(Token(TokenType::KW_case, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "default") {
        tokens.push_back(Token(TokenType::KW_default, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "import") {
        tokens.push_back(Token(TokenType::KW_import, id, cursor.position));
        cursor.consume();
        continue;
      }

      if (id == "struct") {
        tokens.push_back(Token(TokenType::KW_struct, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "enum") {
        tokens.push_back(Token(TokenType::KW_enum, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "class") {
        tokens.push_back(Token(TokenType::KW_class, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "public") {
        tokens.push_back(Token(TokenType::KW_public, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "private") {
        tokens.push_back(Token(TokenType::KW_private, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "guard") {
        tokens.push_back(Token(TokenType::KW_guard, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "override") {
        tokens.push_back(Token(TokenType::KW_override, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "self") {
        tokens.push_back(Token(TokenType::KW_self, id, cursor.position));
        cursor.consume();
        continue;
      }
      if (id == "super") {
        tokens.push_back(Token(TokenType::KW_super, id, cursor.position));
        cursor.consume();
        continue;
      }
      tokens.push_back(Token(TokenType::Identifier, id, cursor.position));
      cursor.consume();
      continue;
    }
  }
  return tokens;
}