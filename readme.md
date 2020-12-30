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

Please see `main.cpp`:

```c++
int main() {
//    std::cout << "Hello, World!" << std::endl;
    test("1 + 4 * 3 + !2 / 2^-1");
    test("!!!3");
    test("(1+2)*3");
    test("a?b:c");

    test("a ? b : c ? d : e"); // "(a ? b : (c ? d : e))"
    test("a ? b ? c : d : e"); //"(a ? (b ? c : d) : e)")
    test("a + b ? c * d : e / f");// "((a + b) ? (c * d) : (e / f))"

    return 0;
}
```

### To Do

- [ ] checking, like left operand in assignment must be a variable
- [ ] error handling, message printing etc
- [ ] add a interpreter to calculate the result, also need an map as environment
- [ ] more operator, e.g., assign, call `f(...)`, postfix operator... 
- [ ] ~~no idea that how to make `Visitor` class as a template, then we can return some result...~~

