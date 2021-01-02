//
// Created by hangs on 2021/1/2.
//

#ifndef PRATTPARSER_RUNTIMEEXCEPTION_H
#define PRATTPARSER_RUNTIMEEXCEPTION_H

#include <stdexcept>

class RuntimeException: public std::runtime_error
{
public:
    explicit RuntimeException(const char *msg):std::runtime_error(msg){}
    explicit RuntimeException(const std::string &msg):std::runtime_error(msg){}
};

#endif //PRATTPARSER_RUNTIMEEXCEPTION_H
