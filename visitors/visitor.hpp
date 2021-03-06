//  ----------------------------------------------------------------------------
//  Header file for the visitor class.        visitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VISITOR_HPP
#define VISITOR_HPP

class AddExpression;
class MultiplyExpression;
class NumberExpression;

class ExpressionVisitor {
  public:
    // virtual void visitAdd(AddExpression&) = 0;
    virtual void visit(const AddExpression&) = 0;
    // virtual void visitMultiply(MultiplyExpression&) = 0;
    virtual void visit(const MultiplyExpression&) = 0;
    // virtual void visitNumber(NumberExpression&) = 0;
    virtual void visit(const NumberExpression&) = 0;

    virtual ~ExpressionVisitor() = default;
};

#endif // VISITOR_HPP
