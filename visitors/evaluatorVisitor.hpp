//  ----------------------------------------------------------------------------
//  Header file for the ExpressionPrinter class.        ExpressionPrinter.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef INC_30F_VARIANTS_PRINTERVISITOR_HPP
#define INC_30F_VARIANTS_PRINTERVISITOR_HPP

#include "ast.hpp"
#include "visitor.hpp"

class EvaluatorVisitor : public ExpressionVisitor {
    double retVal = 0;

  public:
    double evaluate(Expression& expr) {
        expr.accept(*this);
        return retVal;
    }

    void visit(AddExpression& expr) override {

        expr.left().accept(*this);
        double left = retVal;

        expr.right().accept(*this);
        double right = retVal;
        retVal = left + right;
    }
    void visit(MultiplyExpression& expr) override {

        expr.left().accept(*this);
        double left = retVal;

        expr.right().accept(*this);
        double right = retVal;
        retVal = left * right;
    }
    void visit(NumberExpression& expr) override { retVal = expr.getNumber(); }
};

#endif // INC_30F_VARIANTS_PRINTERVISITOR_HPP
