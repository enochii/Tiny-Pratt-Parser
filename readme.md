## Tiny Pratt Parser

Translate simple arithmetic expression to AST.

### Supported operators

- `+ -`
- `* /`
- `^`, exponent
- `? :`, conditional 
- `()`
- `!`

NO Interpreter available now, so no result is calculated, just visible AST.

### Samples

Please see [`main.cpp`](./main.cpp):

```c++
int main() {
//    std::cout << "Hello, World!" << std::endl;
    test("1 + 4 * 3 + !2 / 2^-1"); //(+ (+ 1 (* 4 3)) (/ (! 2) (^ 2 (- 1))))
    test("!+-3"); // (! (+ (- 3)))
    test("(1+2)*3"); // (* ((+ 1 2)) 3)
    test("a?b:c"); // (a ? b : c)

    test("a ? b : c ? d : e"); // "(a ? b : (c ? d : e))"
    test("a ? b ? c : d : e"); //"(a ? (b ? c : d) : e)")
    test("a + b ? c * d : e / f");// "((+ a b) ? (* c d) : (/ e f))"

    test("a = b = 3");
//    test("a = 3 = 2"); // this one will throw an exception

    test("a.b.c");
}
```

### To Do

- [x] checking, like left operand in assignment must be a variable
- [x] error handling, message printing etc
- [ ] add a interpreter to calculate the result, also need an map as environment
- [ ] more operator, e.g., call `f(...)`, postfix operator... 
- [ ] ~~no idea that how to make `Visitor` class as a template, then we can return some result...~~

### Reference

 http://journal.stuffwithstuff.com/2011/03/19/pratt-parsers-expression-parsing-made-easy/ 