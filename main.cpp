#include <iostream>
#include <cassert>
#include "lexer.h"
#include "parser.h"
#include "astPrinter.h"
#include <string>

using namespace std;

void test(string &&s, const std::string& expect)
{
    Lexer lexer(s);
    cout << s << " -> ";

    Parser parser(lexer.getTokens());
    auto ast = parser.run();

    auto astprinter = ASTPrinter();

    string actual = astprinter.stringify(ast);
    cout << actual << "\n";
    assert(actual == expect);
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    test("1 + 4 * 3 + !2 / 2^-1", "(+ (+ 1 (* 4 3)) (/ (! 2) (^ 2 (- 1))))"); //(+ (+ 1 (* 4 3)) (/ (! 2) (^ 2 (- 1))))
    test("!+-3", "(! (+ (- 3)))"); // (! (+ (- 3)))
    test("(1+2)*3", "(* ((+ 1 2)) 3)"); // (* ((+ 1 2)) 3)
    test("a?b:c", "(a ? b : c)"); // (a ? b : c)

    test("a ? b : c ? d : e", "(a ? b : (c ? d : e))"); // "(a ? b : (c ? d : e))"
    test("a ? b ? c : d : e", "(a ? (b ? c : d) : e)"); //"(a ? (b ? c : d) : e)"
    test("a + b ? c * d : e / f", "((+ a b) ? (* c d) : (/ e f))");// "((+ a b) ? (* c d) : (/ e f))"

    test("a = b = 3", "(= a (= b 3))");
//    test("a = 3 = 2"); // this one will throw an exception

    test("a.b.c", "(. (. a b) c)");

    return 0;
}
