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

class Str: public Any {
    std::string str;
public:
    // or we can implement operator<<, operator+ etc.
//    operator std::string() {
//        return str;
//    }
    std::string getStr() {
        return str;
    }
    explicit Str(std::string s):str(std::move(s)) {}
    explicit Str(std::string &&s):str(s) {}
};

class ASTPrinter: public Visitor {
    using Res = shared_ptr<Any>;
public:
//    std::string stringify(Expr& expr)
//    {
//        return ((Str*)expr.accept(*this).get())->getStr();
//    }

    std::string stringify(shared_ptr<Expr>& expr)
    {
        return ((Str*)expr->accept(*this).get())->getStr();

    }

    Res visitAssign(Assign &expr) override {
        std::string ret;
        ret += "(= " + expr.name.lexeme;
        ret += " ";
        ret += stringify(expr.newVal);
        ret += ")";
        return std::make_shared<Str>(ret);
    }

    Res visitBinary(Binary &expr) override {
        std::string ret;
        ret += "(" + expr.op.lexeme + " ";
        ret += stringify(expr.left);
        ret += " ";
        ret += stringify(expr.right);
        ret += ")";
        return std::make_shared<Str>(ret);
    }

    Res visitUnary(Unary &expr) override {
        std::string ret;
        ret += "(" + expr.op.lexeme + " ";
        ret += stringify(expr.expr);
        ret += ")";
        return std::make_shared<Str>(ret);
    }

    Res visitGrouping(Grouping &expr) override {
        std::string ret;
        ret += "(";
        ret += stringify(expr.expr);
        ret += ")";
        return std::make_shared<Str>(ret);
    }

    Res visitNumber(Number &expr) override {
        std::string ret;
        ret += expr.token.lexeme;
        return std::make_shared<Str>(ret);
    }

    Res visitVariable(Variable &expr) override {
        std::string ret;
        ret += expr.var.lexeme;
        return std::make_shared<Str>(ret);
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
        return std::make_shared<Str>(ret);
    }
};

#endif //PRATTPARSER_ASTPRINTER_H
