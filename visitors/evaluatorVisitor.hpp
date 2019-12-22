//  ----------------------------------------------------------------------------
//  Header file for the ExpressionPrinter class.        ExpressionPrinter.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef EVALUATOR_PRINTERVISITOR_HPP
#define EVALUATOR_PRINTERVISITOR_HPP

#include "ast.hpp"
#include "visitor.hpp"

class EvaluatorVisitor : public ExpressionVisitor {
    double retVal = 0;

  public:
    double evaluate(Expression& expr) {
        expr.accept(*this);
        return retVal;
    }

    void visit(const AddExpression& expr) override {

        expr.left().accept(*this);
        double left = retVal;

        expr.right().accept(*this);
        double right = retVal;
        retVal = left + right;
    }
    void visit(const MultiplyExpression& expr) override {

        expr.left().accept(*this);
        double left = retVal;

        expr.right().accept(*this);
        double right = retVal;
        retVal = left * right;
    }
    void visit(const NumberExpression& expr) override {
        retVal = expr.getNumber();
    }
};

#endif // EVALUATOR_PRINTERVISITOR_HPP
