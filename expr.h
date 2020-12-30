// this file is generated automatically by running generate_ast.py

#ifndef PRATTPARSER_EXPR_H
#define PRATTPARSER_EXPR_H
#include "token.h"
#include <memory>

using std::shared_ptr;

template <class R>
class Visitor;
class Expr {
    template <class R>
    R accept(Visitor<R> v);
};

class Assign:public Expr {
public:
    Assign(Token& name, shared_ptr<Expr>& newVal)    {
        this->name = name;
        this->newVal = newVal;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitAssign(this);
    }

    Token name;
    shared_ptr<Expr> newVal;
};

class Binary:public Expr {
public:
    Binary(shared_ptr<Expr>& left, Token& op, shared_ptr<Expr>& right)    {
        this->left = left;
        this->op = op;
        this->right = right;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitBinary(this);
    }
    
    shared_ptr<Expr> left;
    Token op;
    shared_ptr<Expr> right;
};

class Unary:public Expr {
public:
    Unary(Token& op, shared_ptr<Expr>& expr)    {
        this->op = op;
        this->expr = expr;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitUnary(this);
    }
    
    Token op;
    shared_ptr<Expr> expr;
};

class Grouping:public Expr {
public:
    Grouping(shared_ptr<Expr>& expr)    {
        this->expr = expr;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitGrouping(this);
    }
    
    shared_ptr<Expr> expr;
};

class Number:public Expr {
public:
    Number(Token &token): token(token){}
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitNumber(this);
    }
    
    Token token;
};

class Variable:public Expr {
public:
    Variable(Token& var)    {
        this->var = var;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitVariable(this);
    }
    
    Token var;
};

class Conditional:public Expr {
    Conditional(shared_ptr<Expr>& cond, shared_ptr<Expr>& thenExpr, shared_ptr<Expr>& elseExpr)    {
        this->cond = cond;
        this->thenExpr = thenExpr;
        this->elseExpr = elseExpr;
    }
    
    template <class R>
    R accept(Visitor<R> v) {
        return v.visitConditional(this);
    }
    
    shared_ptr<Expr> cond;
    shared_ptr<Expr> thenExpr;
    shared_ptr<Expr> elseExpr;
};

template <class R>
class Visitor {
    virtual R visitAssign(Assign &expr) = 0;
    virtual R visitBinary(Binary &expr) = 0;
    virtual R visitUnary(Unary &expr) = 0;
    virtual R visitGrouping(Grouping &expr) = 0;
    virtual R visitNumber(Number &expr) = 0;
    virtual R visitVariable(Variable &expr) = 0;
    virtual R visitConditional(Conditional &expr) = 0;
};
#endif //PRATTPARSER_EXPR_H
