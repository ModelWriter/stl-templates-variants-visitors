//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "ast.hpp"
#include "evaluatorVisitor.hpp"
#include "printerVisitor.hpp"
#include <iostream>
#include <memory>

int main() {
    {
        auto expression = // ((3 + (4 * 6)) + 2) = 29
            std::make_unique<AddExpression>(
                std::make_unique<AddExpression>(
                    std::make_unique<NumberExpression>(3),
                    std::make_unique<MultiplyExpression>(
                        std::make_unique<NumberExpression>(4),
                        std::make_unique<NumberExpression>(6))),
                std::make_unique<NumberExpression>(2));

        ExpressionPrinter printer;
        EvaluatorVisitor evaluator;
        std::cout << printer.print(*expression) << " = "
                  << evaluator.evaluate(*expression);
    }

    std::cout << "\n";

    {
        auto expression = // ((3 + (4 * (3 * 2))) + 2) = 29
            std::make_unique<AddExpression>(
                std::make_unique<AddExpression>(
                    std::make_unique<NumberExpression>(3),
                    std::make_unique<MultiplyExpression>(
                        std::make_unique<NumberExpression>(4),
                        std::make_unique<MultiplyExpression>(
                            std::make_unique<NumberExpression>(3),
                            std::make_unique<NumberExpression>(2)))),
                std::make_unique<NumberExpression>(2));

        ExpressionPrinter printer;
        EvaluatorVisitor evaluator;
        std::cout << printer.print(*expression) << " = "
                  << evaluator.evaluate(*expression);
    }

    std::cout << "\n";

    {
        auto expression = // ((3 + (4 * ((3 * 1) * 2))) + 2) = 29
            std::make_unique<AddExpression>(
                std::make_unique<AddExpression>(
                    std::make_unique<NumberExpression>(3),
                    std::make_unique<MultiplyExpression>(
                        std::make_unique<NumberExpression>(4),
                        std::make_unique<MultiplyExpression>(
                            std::make_unique<MultiplyExpression>(
                                std::make_unique<NumberExpression>(3),
                                std::make_unique<NumberExpression>(1)),
                            std::make_unique<NumberExpression>(2)))),
                std::make_unique<NumberExpression>(2));

        ExpressionPrinter printer;
        EvaluatorVisitor evaluator;
        std::cout << printer.print(*expression) << " = "
                  << evaluator.evaluate(*expression);
    }

    return 0;
}