// this file is generated automatically by running generate_ast.py

#ifndef PRATTPARSER_EXPR_H
#define PRATTPARSER_EXPR_H
#include "token.h"
#include <memory>

using std::shared_ptr;


class Visitor;
class Expr {
public:
    virtual void accept(Visitor& v) = 0;
};

class Assign:public Expr {
public:
    Assign(Token& name, shared_ptr<Expr>& newVal)    {
        this->name = name;
        this->newVal = newVal;
    }

    void accept(Visitor& v);

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

    void accept(Visitor& v) override;
    
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

    void accept(Visitor& v) override;
    
    Token op;
    shared_ptr<Expr> expr;
};

class Grouping:public Expr {
public:
    explicit Grouping(shared_ptr<Expr>& expr)    {
        this->expr = expr;
    }

    void accept(Visitor& v) override;
    
    shared_ptr<Expr> expr;
};

class Number:public Expr {
public:
    explicit Number(Token &token): token(token){}

    void accept(Visitor& v) override ;

    Token token;
};

class Variable:public Expr {
public:
    explicit Variable(Token& var)    {
        this->var = var;
    }

    void accept(Visitor& v)override;
    
    Token var;
};

class Conditional:public Expr {
public:
    Conditional(shared_ptr<Expr>& cond, shared_ptr<Expr>& thenExpr, shared_ptr<Expr>& elseExpr)    {
        this->cond = cond;
        this->thenExpr = thenExpr;
        this->elseExpr = elseExpr;
    }

    void accept(Visitor& v)override;
    
    shared_ptr<Expr> cond;
    shared_ptr<Expr> thenExpr;
    shared_ptr<Expr> elseExpr;
};

#endif //PRATTPARSER_EXPR_H
