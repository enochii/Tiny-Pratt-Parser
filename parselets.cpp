//
// Created by hangs on 2020/12/30.
//
#include "parselets.h"
#include "parser.h"

shared_ptr<Expr> PrefixOpParselet::parse(Parser& parser, Token &op)
{
    auto val = parser.parsePrecedence(precedence);
    return std::make_shared<Unary>(op, val);
}

shared_ptr<Expr> BinaryOpParselet::parse(Parser& parser, shared_ptr<Expr>& left, Token op)
{
    auto right = parser.parsePrecedence(Precedence(precedence + associativity));
    return std::make_shared<Binary>(left, op, right);
}

shared_ptr<Expr> NumberParselet::parse(Parser &parser, Token& op) {
    return std::make_shared<Number>(op);
}

Precedence InfixParselet::getPrecedence() {
    return precedence;
}
