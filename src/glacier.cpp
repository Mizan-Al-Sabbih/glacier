#include <Compiler/Lexer.h>
#include <iostream>

#define DEBUG_MODE 1

int main() {
  std::string_view content = "(\t) {\t} \n [\t]";
  Lexer lexer(content);
  if (DEBUG_MODE == 1) {
    std::vector<Token> tokens = lexer.tokenize();
    std::cout << "\tType"
              << "\t\t   Lexeme"
              << "\tPosition"
              << "\n\n";
    for (auto &token : tokens) {
      if (token.lexeme == "\n") {
        std::cout << "\t" << token.toString() << "\t\t\t\""
                  << "\\n"
                  << "\"\t  " << token.position.line << ":"
                  << token.position.column << "\n";
      } else {
        std::cout << "\t" << token.toString() << "\t\t\"" << token.lexeme
                  << "\"\t\t  " << token.position.line << ":"
                  << token.position.column << "\n";
      }
    }
  }
  return 0;
}