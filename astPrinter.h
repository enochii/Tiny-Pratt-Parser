//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_ASTPRINTER_H
#define PRATTPARSER_ASTPRINTER_H

#include <string>
#include <utility>
#include "expr.h"
#include "visitor.h"
#include "any.h"


class ASTPrinter: public Visitor {
    using Res = Any;
public:
    std::string stringify(shared_ptr<Expr>& expr)
    {
        Any a = expr->accept(*this);
        return *a.get<std::string>();
    }

    Res visitAssign(Assign &expr) override {
        std::string ret;
        ret += "(= " + expr.name.lexeme;
        ret += " ";
        ret += stringify(expr.newVal);
        ret += ")";
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitBinary(Binary &expr) override {
        std::string ret;
        ret += "(" + expr.op.lexeme + " ";
        ret += stringify(expr.left);
        ret += " ";
        ret += stringify(expr.right);
        ret += ")";
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitUnary(Unary &expr) override {
        std::string ret;
        ret += "(" + expr.op.lexeme + " ";
        ret += stringify(expr.expr);
        ret += ")";
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitGrouping(Grouping &expr) override {
        std::string ret;
        ret += "(";
        ret += stringify(expr.expr);
        ret += ")";
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitNumber(Number &expr) override {
        std::string ret;
        ret += expr.token.lexeme;
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitVariable(Variable &expr) override {
        std::string ret;
        ret += expr.var.lexeme;
        return Any(std::make_shared<std::string>(ret));
    }

    Res visitConditional(Conditional &expr) override {
        std::string ret;
        ret += "(" ;
        ret += stringify(expr.cond);
        ret += " ? ";
        ret += stringify(expr.thenExpr);
        ret += " : ";
        ret += stringify(expr.elseExpr);
        ret += ")";
        return Any(std::make_shared<std::string>(ret));
    }
};

#endif //PRATTPARSER_ASTPRINTER_H
