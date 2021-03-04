//
// Created by hangs on 2020/12/30.
//

#include "expr.h"
#include "visitor.h"

Expr::~Expr() = default;

shared_ptr<Any> Assign::accept(Visitor& v) {
    return v.visitAssign(*this);
}

Assign::Assign(Token &name, shared_ptr<Expr> &newVal)
            :name(name), newVal(newVal) {}

shared_ptr<Any> Binary::accept(Visitor& v) {
    return v.visitBinary(*this);
}

Binary::Binary(shared_ptr<Expr> &left, Token &op, shared_ptr<Expr> &right)
            :left(left), op(op), right(right){}

shared_ptr<Any> Unary::accept(Visitor& v) {
    return v.visitUnary(*this);
}

Unary::Unary(Token &op, shared_ptr<Expr> &expr)
            :op(op), expr(expr){}

shared_ptr<Any> Grouping::accept(Visitor& v) {
    return v.visitGrouping(*this);
}

Grouping::Grouping(shared_ptr<Expr> &expr)
            :expr(expr){}

Number::Number(Token &token): token(token){}

shared_ptr<Any> Number::accept(Visitor& v) {
    return v.visitNumber(*this);
}

shared_ptr<Any> Variable::accept(Visitor& v) {
    return v.visitVariable(*this);
}

Variable::Variable(Token &var)
            :var(var){}

shared_ptr<Any> Conditional::accept(Visitor &v) {
    return v.visitConditional(*this);
}

Conditional::Conditional(shared_ptr<Expr> &cond, shared_ptr<Expr> &thenExpr, shared_ptr<Expr> &elseExpr)
            :cond(cond), thenExpr(thenExpr), elseExpr(elseExpr){}

