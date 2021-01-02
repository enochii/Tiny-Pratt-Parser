//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_LEXER_H
#define PRATTPARSER_LEXER_H

#include "token.h"
#include <vector>
#include <string>
#include <iostream>

//#define DEBUG_PRINT_TOKEN

class Lexer {
public:
    explicit Lexer(std::string &s): source(s)
    {
        run();
    }

    explicit Lexer(std::string &&s): source(s)
    {
        run();
    }

    std::vector<Token>& getTokens()
    {
        return tokens;
    }

private:
    void run()
    {
        while (current < source.size()) {
            start = current;

            char c = advance();
            switch (c) {
                case '+':
                    addToken(TOKEN_PLUS);break;
                case '-':
                    addToken(TOKEN_MINUS);break;
                case '*':
                    addToken(TOKEN_STAR);break;
                case '/':
                    addToken(TOKEN_SLASH);break;
                case '!':
                    addToken(TOKEN_BANG);break;
                case '^':
                    addToken(TOKEN_CARET);break;
                case '(':
                    addToken(TOKEN_LEFT_PAREN);break;
                case ')':
                    addToken(TOKEN_RIGHT_PAREN);break;
                case '?':
                    addToken(TOKEN_QUESTION);break;
                case ':':
                    addToken(TOKEN_COLON);break;
                case '=':
                    addToken(TOKEN_ASSIGN);break;

                default:
                    if(isAlpha(c)) {
                        identifier();
                    } else if(isDigit(c)){
                        number();
                    } else {

                    }
                    break;
            }
        }

        start = current; //
        addToken(TOKEN_EOF);

        std::cout << "tokens: ";
        for(Token &token:tokens) {
            std::cout << "[" << token.lexeme << "]";
        }
        std::cout << "\n";
    }

    void addToken(TokenType type)
    {
        tokens.emplace_back(type, source.substr(start, current - start));
    }


    char advance()
    {
        return source[current++];
    }

    char peek()
    {
        return source[current];
    }

    bool isAlpha(char c)
    {
        return  c == '_' ||
                c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z';
    }

    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    void number()
    {
        while (isDigit(peek())) advance();
        addToken(TOKEN_NUM);
    }

    void identifier()
    {
        while (isAlpha(peek()) || isDigit(peek())) advance();
        addToken(TOKEN_ID);
    }
private:
    int start = 0;
    int current = 0;
    std::string source;

    std::vector<Token> tokens;
};

#endif //PRATTPARSER_LEXER_H
