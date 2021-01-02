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
    virtual ~Expr()=0;
};

class Assign:public Expr {
public:
    Assign(Token& name, shared_ptr<Expr>& newVal);
    void accept(Visitor& v) override;
    ~Assign() override = default;

    Token name;
    shared_ptr<Expr> newVal;
};

class Binary:public Expr {
public:
    Binary(shared_ptr<Expr>& left, Token& op, shared_ptr<Expr>& right);
    void accept(Visitor& v) override;
    ~Binary() override = default;
    
    shared_ptr<Expr> left;
    Token op;
    shared_ptr<Expr> right;
};

class Unary:public Expr {
public:
    Unary(Token& op, shared_ptr<Expr>& expr);
    void accept(Visitor& v) override;
    ~Unary() override = default;
    
    Token op;
    shared_ptr<Expr> expr;
};

class Grouping:public Expr {
public:
    explicit Grouping(shared_ptr<Expr>& expr);

    void accept(Visitor& v) override;
    
    shared_ptr<Expr> expr;
};

class Number:public Expr {
public:
    explicit Number(Token &token);
    void accept(Visitor& v) override ;
    ~Number() override = default;

    Token token;
};

class Variable:public Expr {
public:
    explicit Variable(Token& var);
    void accept(Visitor& v)override;
    ~Variable() override = default;

    Token var;
};

class Conditional:public Expr {
public:
    Conditional(shared_ptr<Expr>& cond, shared_ptr<Expr>& thenExpr, shared_ptr<Expr>& elseExpr);
    void accept(Visitor& v)override;
    ~Conditional() override = default;
    
    shared_ptr<Expr> cond;
    shared_ptr<Expr> thenExpr;
    shared_ptr<Expr> elseExpr;
};

#endif //PRATTPARSER_EXPR_H
