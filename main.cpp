#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "astPrinter.h"
#include <string>

using namespace std;

void test(string &&s)
{
    Lexer lexer(s);
    cout << s << " -> ";

    Parser parser(lexer.getTokens());
    auto ast = parser.run();

    auto astprinter = ASTPrinter();

    astprinter.stringify(ast);
    cout << "\n";
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    test("1 + 4 * 3 + !2 / 2^-1");
    test("!!!3");
    return 0;
}
