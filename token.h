//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_TOKEN_H
#define PRATTPARSER_TOKEN_H

#include <string>

enum Precedence {
    PREC_NONE,
    PREC_ASSIGN,
//    PREC_COLON, // a?b?c:d:f
    PREC_QUESTION,
    PREC_TERM,
    PREC_FACTOR,
    PREC_EXPONENT,
    PREC_UNARY,
    PREC_DOT,
//    PREC_GROUPING
};

enum Associativity {
    RIGHT,
    LEFT // guess why LEFT is after RIGHT
};

enum TokenType {
    TOKEN_ASSIGN,       // =
    TOKEN_PLUS,         // +
    TOKEN_MINUS,        // -
    TOKEN_STAR,         // *
    TOKEN_SLASH,        // /
    TOKEN_CARET,        // ^
    TOKEN_BANG,         // !
    TOKEN_QUESTION,     // ?
    TOKEN_COLON,        // :
    TOKEN_LEFT_PAREN,   // (
    TOKEN_RIGHT_PAREN,  // )
    TOKEN_DOT,          // .
    TOKEN_NUM,
    TOKEN_ID,
    TOKEN_EOF,
};

struct Token {
//    Token(TokenType type, const char *start, int length)
//    : type(type), start(start), length(length){}
    Token(TokenType type, std::string& s): type(type), lexeme(s)
    {}
    Token(TokenType type, std::string&& s): type(type), lexeme(s)
    {}


    TokenType type;
    std::string lexeme;
//    const char *start;
//    int length;
};
#endif //PRATTPARSER_TOKEN_H
