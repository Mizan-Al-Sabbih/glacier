#pragma once

#include <memory>
#include <string>
#include <vector>

#include "utility.h"

class ASTNode {
public:
  virtual ~ASTNode() = default;
};

using ASTNodePtr = std::shared_ptr<ASTNode>;

class Expression : public ASTNode {};

class Statement : public ASTNode {};

class VariableDeclaration : public Statement {
public:
  VariableDeclaration(const std::string &name, ASTNodePtr initializer,
                      Span span)
      : name(name), initializer(initializer), span(span) {}

  std::string name;
  ASTNodePtr initializer;
  Span span;
};

class BinaryExpression : public Expression {
public:
  BinaryExpression(const std::string &op, ASTNodePtr left, ASTNodePtr right,
                   Span span)
      : op(op), left(left), right(right), span(span) {}

  std::string op;
  ASTNodePtr left;
  ASTNodePtr right;
  Span span;
};

class NumberLiteral : public Expression {
public:
  explicit NumberLiteral(int value, Span span) : value(value), span(span) {}

  int value;
  Span span;
};

class AST {
public:
  void add_node(ASTNodePtr node) { nodes.push_back(node); }

  const std::vector<ASTNodePtr> &get_nodes() const { return nodes; }

private:
  std::vector<ASTNodePtr> nodes;
};
