#include <Compiler/Lexer.h>
#include <iostream>

int main() {
  std::string_view content = "var x = 5";
  Lexer lexer(content);
  std::vector<Token> tokens = lexer.tokenize();

  for (auto &token : tokens) {
#if DEBUG_MODE == 1
    std::cout << "Type = " << token.toString() << ", Lexeme = " << token.lexeme << ", Position = " << token.position.line << ":" << token.position.column << ";\n\n";
#endif
  }
  return 0;
}