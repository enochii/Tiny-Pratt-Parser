//
// Created by hangs on 2020/12/30.
//

#include "expr.h"
#include "visitor.h"

void Assign::accept(Visitor& v) {
    v.visitAssign(*this);
}

void Binary::accept(Visitor& v) {
    return v.visitBinary(*this);
}

void Unary::accept(Visitor& v) {
    v.visitUnary(*this);
}

void Grouping::accept(Visitor& v) {
    v.visitGrouping(*this);
}

void Number::accept(Visitor& v) {
    return v.visitNumber(*this);
}

void Variable::accept(Visitor& v) {
    v.visitVariable(*this);
}

void Conditional::accept(Visitor &v) {
    v.visitConditional(*this);
}

