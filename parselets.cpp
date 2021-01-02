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

Precedence BinaryOpParselet::getPrecedence() {
    return precedence;
}

shared_ptr<Expr> NumberParselet::parse(Parser &parser, Token& op) {
    return std::make_shared<Number>(op);
}

shared_ptr<Expr> GroupingParselet::parse(Parser &parser, Token &op) {
    // "(" already eaten
    auto expr = parser.parsePrecedence(PREC_ASSIGN);
    parser.consume(TOKEN_RIGHT_PAREN, "Expect a ')'");
    return std::make_shared<Grouping>(expr);
}

shared_ptr<Expr> ConditionalParselet::parse(Parser &parser, shared_ptr<Expr> &left, Token op)
{
    auto thenExpr = parser.parsePrecedence(PREC_ASSIGN);
    parser.consume(TOKEN_COLON, "Expect a colon");
    auto elseExpr = parser.parsePrecedence(PREC_QUESTION);

    return std::make_shared<Conditional>(left, thenExpr, elseExpr);
}

Precedence ConditionalParselet::getPrecedence() {
    return PREC_QUESTION;
}

shared_ptr<Expr> VariableParselet::parse(Parser &parser, Token &op) {
    return std::make_shared<Variable>(op);
}

shared_ptr<Expr> AssignParselet::parse(Parser &parser, shared_ptr<Expr> &left, Token op) {
    shared_ptr<Variable> ptr = std::dynamic_pointer_cast<Variable>(left);
    if(ptr == nullptr) {
        parser.error(op, "left operand should be a variable");
    }

    auto right = parser.parsePrecedence(PREC_ASSIGN);
    return std::make_shared<Assign>(ptr->var, right);
}

Precedence AssignParselet::getPrecedence() {
    return PREC_ASSIGN;
}
