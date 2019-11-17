//  ----------------------------------------------------------------------------
//  Header file for the ast class.        ast.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef INC_30F_VARIANTS_AST_HPP
#define INC_30F_VARIANTS_AST_HPP

#include "visitor.hpp"
#include <cassert>
#include <iostream>
#include <memory>

class Expression {
  public:
    virtual ~Expression() = default;
    virtual void accept(ExpressionVisitor&){};
};

using ExpressionPtr = std::unique_ptr<Expression>;

class BinaryExpression : public Expression {
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;

  public:
    BinaryExpression(std::unique_ptr<Expression> left,
                     std::unique_ptr<Expression> right)
        : lhs(std::move(left)), rhs(std::move(right)) {
        assert(lhs && rhs);
    }

    [[nodiscard]] Expression& left() const { return *lhs; }
    [[nodiscard]] Expression& right() const { return *rhs; }
};

class AddExpression : public BinaryExpression {
  public:
    using BinaryExpression::BinaryExpression;

    void accept(ExpressionVisitor& visitor) override {
        visitor.visitAdd(*this);
    }
};

class MultiplyExpression : public BinaryExpression {
  public:
    using BinaryExpression::BinaryExpression;

    void accept(ExpressionVisitor& visitor) override {
        visitor.visitMultiply(*this);
    }
};

class NumberExpression : public Expression {
    double number;

  public:
    explicit NumberExpression(double d) : number(d) {}

    [[nodiscard]] double getNumber() const { return number; }

    void accept(ExpressionVisitor& visitor) override {
        visitor.visitNumber(*this);
    }
};

#endif // INC_30F_VARIANTS_AST_HPP
