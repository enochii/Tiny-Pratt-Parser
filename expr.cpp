//
// Created by hangs on 2020/12/30.
//

#include "expr.h"
#include "visitor.h"

Expr::~Expr() = default;

void Assign::accept(Visitor& v) {
    v.visitAssign(*this);
}

Assign::Assign(Token &name, shared_ptr<Expr> &newVal)
            :name(name), newVal(newVal) {}

void Binary::accept(Visitor& v) {
    return v.visitBinary(*this);
}

Binary::Binary(shared_ptr<Expr> &left, Token &op, shared_ptr<Expr> &right)
            :left(left), op(op), right(right){}

void Unary::accept(Visitor& v) {
    v.visitUnary(*this);
}

Unary::Unary(Token &op, shared_ptr<Expr> &expr)
            :op(op), expr(expr){}

void Grouping::accept(Visitor& v) {
    v.visitGrouping(*this);
}

Grouping::Grouping(shared_ptr<Expr> &expr)
            :expr(expr){}

Number::Number(Token &token): token(token){}

void Number::accept(Visitor& v) {
    return v.visitNumber(*this);
}

void Variable::accept(Visitor& v) {
    v.visitVariable(*this);
}

Variable::Variable(Token &var)
            :var(var){}

void Conditional::accept(Visitor &v) {
    v.visitConditional(*this);
}

Conditional::Conditional(shared_ptr<Expr> &cond, shared_ptr<Expr> &thenExpr, shared_ptr<Expr> &elseExpr)
            :cond(cond), thenExpr(thenExpr), elseExpr(thenExpr){}

