cmake_minimum_required(VERSION 3.17)
project(PrattParser)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrattParser main.cpp token.h parser.h parser.cpp parselets.h parselets.cpp lexer.h astPrinter.h visitor.h expr.cpp)