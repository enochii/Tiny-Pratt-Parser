//
// Created by hangs on 2020/12/30.
//

#include "parser.h"
#include "token.h"
#include "expr.h"
#include <iostream>
#include <string>

class Parser;


shared_ptr<Expr> Parser::parsePrecedence(Precedence precedence)
{
    advance();
    TokenType op = previous().type;

    if(!prefixes.count(op)) {
        error(previous(), "no such operator ");
    }
    auto left = prefixes[op]->parse(*this, previous());

    while (precedence <= infixes[peek().type]->getPrecedence()) {
        Token op1 = peek();
        advance(); // skip op
        left = infixes[peek().type]->parse(*this, left, op1);
    }

    return left;
}

Parser::Parser(std::vector<Token>&& tokens):tokens(tokens){
    record(TOKEN_NUM, std::make_shared<NumberParselet>());

    prefix(TOKEN_PLUS, PREC_UNARY);
    prefix(TOKEN_MINUS, PREC_UNARY);
    prefix(TOKEN_BANG, PREC_UNARY);

    infixLeft(TOKEN_PLUS, PREC_TERM);
    infixLeft(TOKEN_MINUS, PREC_TERM);
    infixLeft(TOKEN_STAR, PREC_FACTOR);
    infixLeft(TOKEN_SLASH, PREC_FACTOR);

    infixRight(TOKEN_CARET, PREC_EXPONENT);
}

void Parser::advance() {
    ++current;
}

void Parser::consume(TokenType type, std::string &msg) {
    if(!match(type)) {
        std::cerr << msg << '\n';
    }
}

bool Parser::match(TokenType type) {
    if(peek().type == type) {
        advance();
        return true;
    }
    return false;
}

Token &Parser::previous() {
    return tokens.at(current-1);
}

Token &Parser::peek() {
    return tokens.at(current);
}

Token &Parser::next() {
    return tokens.at(current+1);
}

void Parser::record(TokenType type, shared_ptr<PrefixOpParselet>& parselet)
{
    prefixes[type] = parselet;
}

void Parser::record(TokenType type, shared_ptr<InfixParselet>&& parselet)
{
    infixes[type] = parselet;
}

void Parser::record(TokenType type, shared_ptr<PrefixParselet>&& parselet)
{
    prefixes[type] = parselet;
}

void Parser::record(TokenType type, shared_ptr<InfixParselet>& parselet)
{
    infixes[type] = parselet;
}

void Parser::infix(TokenType type, Precedence prec, Associativity assoc)
{
    record(type, std::make_shared<BinaryOpParselet>(prec, assoc));
}

void Parser::prefix(TokenType type, Precedence prec)
{
    record(type, std::make_shared<PrefixOpParselet>(prec));
}

void Parser::infixLeft(TokenType type, Precedence prec)
{
    infix(type, prec, LEFT);
}

void Parser::infixRight(TokenType type, Precedence prec)
{
    infix(type, prec, RIGHT);
}

void Parser::error(Token token, std::string &&msg)
{
    std::cerr << msg << '\n';
    hasErr = true;
}

