#include <iostream>
#include <string_view>
#include <memory>

#include "utility.h"
#include "lexer.h"
#include "ast.h"

int main() {
  std::string_view input = "var x = 5 \n";
  Compiler::Lexer lexer(input);
  auto tokens = lexer.analyze();
  for (const auto &token : tokens) {
    std::cout << "Token_ID_Number: " << static_cast<int>(token.type) << " | Span: [" << token.span.start << ", " << token.span.end << "]\n";
  }

  Compiler::AST ast;
  auto num_literal = std::make_shared<Compiler::NumberLiteral>(42);
  auto var_decl = std::make_shared<Compiler::VariableDeclaration>("x", num_literal);

  ast.add_node(var_decl);

  const auto &nodes = ast.get_nodes();
  for (const auto &node : nodes) {
    if (auto var = std::dynamic_pointer_cast<Compiler::VariableDeclaration>(node)) {
      std::cout << "\nVariable Declaration: " << var->name << " = ";
      if (auto num = std::dynamic_pointer_cast<Compiler::NumberLiteral>(var->initializer)) {
        std::cout << num->value << "\n";
      }
    }
  }
  std::cout << "Process ended";
  return 0;
}
