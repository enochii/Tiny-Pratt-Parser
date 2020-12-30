//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_ASTPRINTER_H
#define PRATTPARSER_ASTPRINTER_H

#include "expr.h"
#include "visitor.h"

class ASTPrinter: public Visitor {
    using Res = void;
public:
    Res stringify(Expr& expr)
    {
        expr.accept(*this);
    }

    Res stringify(shared_ptr<Expr>& expr)
    {
        return expr->accept(*this);
    }

    Res visitAssign(Assign &expr) override {
        std::cout << "(= " + expr.name.lexeme;
        std::cout << " ";
        stringify(expr.newVal);
        std::cout << ")";
    }

    Res visitBinary(Binary &expr) override {
        std::cout << "(" + expr.op.lexeme + " ";
        stringify(expr.left);
        std::cout << " ";
        stringify(expr.right);
        std::cout << ")";
    }

    Res visitUnary(Unary &expr) override {
        std::cout << "(" + expr.op.lexeme + " ";
        stringify(expr.expr);
        std::cout << ")";
    }

    Res visitGrouping(Grouping &expr) override {
        std::cout << "(";
        stringify(expr.expr);
        std::cout << ")";
    }

    Res visitNumber(Number &expr) override {
        std::cout << expr.token.lexeme;
    }

    Res visitVariable(Variable &expr) override {
        std::cout << expr.var.lexeme;
    }

    Res visitConditional(Conditional &expr) override {
        std::cout << "(" ;
        stringify(expr.cond);
        std::cout << " ? ";
        stringify(expr.thenExpr);
        std::cout << " : ";
        stringify(expr.elseExpr);
        std::cout << ")";
    }
};

#endif //PRATTPARSER_ASTPRINTER_H
