#include <iostream>
#include <string_view>

#include "lexer.h"

int main() {
  std::string_view input = "var x = 5 \n func show_x() ";
  Compiler::Lexer lexer(input);
  auto tokens = lexer.analyze();
  for (const auto &token : tokens) {
    std::cout << "Token_ID_Number: " << static_cast<int>(token.type) << " | Span: [" << token.span.start << ", " << token.span.end << "]\n";
  }
  std::cout << "Process ended";
  return 0;
}
