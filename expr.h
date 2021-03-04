// this file is generated automatically by running generate_ast.py

#ifndef PRATTPARSER_EXPR_H
#define PRATTPARSER_EXPR_H
#include "token.h"
#include "any.h"
#include <memory>

using std::shared_ptr;


class Visitor;
class Expr {
public:
    virtual shared_ptr<Any> accept(Visitor& v) = 0;

protected:
//    virtual ~Expr()=0;
    ~Expr();
};

class Assign:public Expr {
public:
    Assign(Token& name, shared_ptr<Expr>& newVal);
    shared_ptr<Any> accept(Visitor& v) override;
    ~Assign()  = default;

    Token name;
    shared_ptr<Expr> newVal;
};

class Binary:public Expr {
public:
    Binary(shared_ptr<Expr>& left, Token& op, shared_ptr<Expr>& right);
    shared_ptr<Any> accept(Visitor& v) override;
    ~Binary()  = default;
    
    shared_ptr<Expr> left;
    Token op;
    shared_ptr<Expr> right;
};

class Unary:public Expr {
public:
    Unary(Token& op, shared_ptr<Expr>& expr);
    shared_ptr<Any> accept(Visitor& v) override;
    ~Unary()  = default;
    
    Token op;
    shared_ptr<Expr> expr;
};

class Grouping:public Expr {
public:
    explicit Grouping(shared_ptr<Expr>& expr);

    shared_ptr<Any> accept(Visitor& v) override;
    
    shared_ptr<Expr> expr;
};

class Number:public Expr {
public:
    explicit Number(Token &token);
    shared_ptr<Any> accept(Visitor& v) override ;
    ~Number()  = default;

    Token token;
};

class Variable:public Expr {
public:
    explicit Variable(Token& var);
    shared_ptr<Any> accept(Visitor& v)override;
    ~Variable()  = default;

    Token var;
};

class Conditional:public Expr {
public:
    Conditional(shared_ptr<Expr>& cond, shared_ptr<Expr>& thenExpr, shared_ptr<Expr>& elseExpr);
    shared_ptr<Any> accept(Visitor& v)override;
    ~Conditional()  = default;
    
    shared_ptr<Expr> cond;
    shared_ptr<Expr> thenExpr;
    shared_ptr<Expr> elseExpr;
};

#endif //PRATTPARSER_EXPR_H
