//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_VISITOR_H
#define PRATTPARSER_VISITOR_H
#include "expr.h"

class Visitor {
public:
    virtual void visitAssign(Assign &expr) = 0;
    virtual void visitBinary(Binary &expr) = 0;
    virtual void visitUnary(Unary &expr) = 0;
    virtual void visitGrouping(Grouping &expr) = 0;
    virtual void visitNumber(Number &expr) = 0;
    virtual void visitVariable(Variable &expr) = 0;
    virtual void visitConditional(Conditional &expr) = 0;
};

#endif //PRATTPARSER_VISITOR_H
