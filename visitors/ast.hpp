//  ----------------------------------------------------------------------------
//  Header file for the ast class.        ast.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef AST_HPP
#define AST_HPP

#include "visitor.hpp"
#include <cassert>
#include <iostream>
#include <memory>

class Expression {
  public:
    virtual ~Expression() = default;
    virtual void accept(ExpressionVisitor&) const {};
};

using ExpressionPtr = std::unique_ptr<Expression>;

class BinaryExpression : public Expression {
    const std::unique_ptr<Expression> lhs;
    const std::unique_ptr<Expression> rhs;

  public:
    BinaryExpression(std::unique_ptr<Expression> left,
                     std::unique_ptr<Expression> right)
        : lhs(std::move(left)), rhs(std::move(right)) {
        assert(lhs && rhs);
    }

    [[nodiscard]] Expression& left() { return *lhs; }
    [[nodiscard]] Expression& right() const { return *rhs; }
};

class AddExpression : public BinaryExpression {
  public:
    using BinaryExpression::BinaryExpression;

    void accept(ExpressionVisitor& visitor) const override {
        // visitor.visitAdd(*this);
        visitor.visit(*this);
    }
};

class MultiplyExpression : public BinaryExpression {
  public:
    using BinaryExpression::BinaryExpression;

    void accept(ExpressionVisitor& visitor) const override {
        // visitor.visitMultiply(*this);
        visitor.visit(*this);
    }
};

class NumberExpression : public Expression {
    const double number;

  public:
    explicit NumberExpression(double d) : number(d) {}

    [[nodiscard]] double getNumber() const { return number; }

    void accept(ExpressionVisitor& visitor) const override {
        // visitor.visitNumber(*this);
        visitor.visit(*this);
    }
};

#endif // AST_HPP
