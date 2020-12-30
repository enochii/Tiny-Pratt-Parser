//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_PARSELETS_H
#define PRATTPARSER_PARSELETS_H

//#include <memory>
#include "token.h"
#include "expr.h"

class Parser;

class PrefixParselet {
public:
    virtual shared_ptr<Expr> parse(Parser& parser, Token &op) = 0;
};

class InfixParselet {
public:
    virtual shared_ptr<Expr> parse(Parser& parser, shared_ptr<Expr>& left, Token op) = 0;

    InfixParselet(Precedence prec, Associativity assoc):
    precedence(prec), associativity(assoc){}

    Precedence getPrecedence();

protected:
    Precedence precedence;
    Associativity associativity;
};

class PrefixOpParselet: public PrefixParselet {
public:
    PrefixOpParselet(Precedence prec): precedence(prec){}

    shared_ptr<Expr> parse(Parser& parser, Token &op)override;
protected:
    Precedence precedence;
};

class BinaryOpParselet: public InfixParselet {
public:
    BinaryOpParselet(Precedence prec, Associativity assoc):
        InfixParselet(prec, assoc){}

    shared_ptr<Expr> parse(Parser& parser, shared_ptr<Expr>& left, Token op)override;
};

class NumberParselet: public PrefixParselet {
public:
    NumberParselet(){}

    shared_ptr<Expr> parse(Parser& parser, Token &op)override;
};

#endif //PRATTPARSER_PARSELETS_H
