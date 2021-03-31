//
// Created by hangs on 2021/3/4.
//

#ifndef PRATTPARSER_ANY_H
#define PRATTPARSER_ANY_H

#include <memory>

// any Resurned type
class Any {
    std::shared_ptr<void> ptr;

public:
    template<class T>
    Any(std::shared_ptr<T> p):ptr(p) {}

    template<class T>
    T* get()
    {
        return (T*)ptr.get();
    }
};

#endif //PRATTPARSER_ANY_H
