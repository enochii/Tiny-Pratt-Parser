//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_PARSER_H
#define PRATTPARSER_PARSER_H

#include "expr.h"
#include "token.h"
#include "parselets.h"
#include <vector>
#include <unordered_map>


class Parser {
public:
    Parser(std::vector<Token>&& tokens);
    shared_ptr<struct Expr> parsePrecedence(Precedence precedence);

    void advance();
    void consume(TokenType type, std::string &msg);
    bool match(TokenType type);
    Token& previous();
    Token& peek();
    Token& next();

    void record(TokenType type, shared_ptr<PrefixOpParselet>& parselet);
    void record(TokenType type, shared_ptr<InfixParselet>& parselet);

    void prefix(TokenType type, Precedence prec);
    void infix(TokenType type, Precedence prec, Associativity assoc);

    void infixLeft(TokenType type, Precedence prec);
    void infixRight(TokenType type, Precedence prec);

private:
//    Token current_;
//    Token previous_;
    bool hasErr = false;
    bool hasRuntimeErr = false;

    std::vector<Token> tokens;
    int current = 0;

    std::unordered_map<TokenType, shared_ptr<PrefixParselet>> prefixes;
    std::unordered_map<TokenType, shared_ptr<InfixParselet>> infixes;

    void record(TokenType type, shared_ptr<InfixParselet> &&parselet);

    void record(TokenType type, shared_ptr<PrefixParselet> &&parselet);

    void error(Token token, std::string &&msg);
};

#endif //PRATTPARSER_PARSER_H
