//
// Created by hangs on 2021/1/2.
//

#ifndef PRATTPARSER_ParseException_H
#define PRATTPARSER_ParseException_H

#include <stdexcept>

class parseException: public std::runtime_error
{
public:
    explicit parseException(const char *msg): std::runtime_error(msg){}
    explicit parseException(const std::string &msg): std::runtime_error(msg){}
};

#endif //PRATTPARSER_ParseException_H
