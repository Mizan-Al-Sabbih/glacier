#include <Compiler/Lexer.h>

Lexer::Lexer(std::string_view& content) : cursor(content) {}

std::vector<Token> Lexer::tokenize() {
  std::vector<Token> tokens;
  while (cursor.position.index < cursor.contentLength()) {
    char currentChar = cursor.peek();

    if (currentChar == ' ' || currentChar == '\t') {
      cursor.consume();
      continue;
    }
    if (currentChar == '\n') {
      tokens.push_back(Token(TokenType::Newline, "\n", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '(') {
      tokens.push_back(Token(TokenType::LParen, "(", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ')') {
      tokens.push_back(Token(TokenType::RParen, ")", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '{') {
      tokens.push_back(Token(TokenType::LBrace, "{", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '}') {
      tokens.push_back(Token(TokenType::RBrace, "}", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '[') {
      tokens.push_back(Token(TokenType::LBrace, "[", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ']') {
      tokens.push_back(Token(TokenType::RBrace, "]", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ',') {
      tokens.push_back(Token(TokenType::Comma, ",", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == '.') {
      tokens.push_back(Token(TokenType::Dot, ".", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ':') {
      tokens.push_back(Token(TokenType::Colon, ":", cursor.position));
      cursor.consume();
      continue;
    }
    if (currentChar == ':' && cursor.consume() == ':') {
      tokens.push_back(Token(TokenType::ColonColon, "::", cursor.position));
      cursor.consume();
      continue;
    }
    if (isalnum(currentChar)) {
      std::string id = "";
      while (isalnum(cursor.consume())) {
        id += currentChar;
      }
      if (id == "true") {
  }
  return tokens;
}