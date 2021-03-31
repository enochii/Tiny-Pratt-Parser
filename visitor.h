//
// Created by hangs on 2020/12/30.
//

#ifndef PRATTPARSER_VISITOR_H
#define PRATTPARSER_VISITOR_H
#include "expr.h"


class Visitor {
    using Res = Any;
public:
    virtual Res visitAssign(Assign &expr) = 0;
    virtual Res visitBinary(Binary &expr) = 0;
    virtual Res visitUnary(Unary &expr) = 0;
    virtual Res visitGrouping(Grouping &expr) = 0;
    virtual Res visitNumber(Number &expr) = 0;
    virtual Res visitVariable(Variable &expr) = 0;
    virtual Res visitConditional(Conditional &expr) = 0;
};

#endif //PRATTPARSER_VISITOR_H
