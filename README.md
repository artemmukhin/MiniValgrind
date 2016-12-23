# MiniValgrind
Simple tool for memory leak detection in programs written in simple C-like language (MiniC).
Lexer and parser are generated by Flex and Bison.  
Works on Windows with Cygwin and on Linux.
## Building
Requires gcc, Flex and Bison
```
$ make
```

## Usage
#### Run
```
$ ./MiniValgrind < Tests/test1.txt
```
#### Output
If there are memory leaks in your program, you will see warning like this:
```
Memory leaks: 1 blocks, total size = 10 int
```
If there are syntax errors in your program, you will see error like this:
```
syntax error, line 2
```
If there are runtime errors, you will see error like this:
```
Error:    Invalid value's type
Aborted.
```

## Testing
You can run unit test:
```
$ python Tests/UnitTest.py
```
or memory test of MiniValgrind (requires original Valgrind)
```
$ python Test/MemoryTest.py
```

## MiniC overview
MiniC program is enclosed between`#begin` and `#end`.
All MiniC programs must have a `main()` function — entry point of the program.

#### Data types
There are three data types in MiniC: integer (`int`), pointer to integer (`ptr`) and array of integer (`arr`):
```
int x;
int y = 15;
ptr p = &x; // now *p == 15
```
`ptr` can be used as reference to array:
```
arr a[2];
a[0] = 1;
a[1] = 2;
ptr p = a; // now p[0] == 1, p[1] == 2
p[0] = 5;  // now p[0] == a[0] == 5
```

#### Operators and statements
Arithmetic (`+, -, *, /, %, ++, --`), logical (`!, &&, ||`) and comparison operators (`<, <=, ==, >=, >, !=`) are similar to C.

Statements: `if, for, while, return`:
```
if (x == y) {
    while (x < 10) {
        z++;
    }
else {
    for (int i = 0; i < 5; i++;) { // yes, there is a semicolon after i++
        print(i);
    }
}

```

#### Functions
MiniC has two manual memory management functions: `malloc` and `free` (similar to C):
```
ptr p = malloc(10); // now it has p[0], ..., p[9]
free(p); // delete p[0], ..., p[9]
```
Also MiniC has `print` function:
```
int x = 10;
int y = 5;
print(2 * x + y + 7); // "32"
```
You can define your own functions (return type may be `int`, `ptr` or `arr`):
```
int swap(ptr p, ptr q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
    return 0;
}
```

#### Global variables
You can define global variables by using inside your program (i.e. between `#begin` and `#end`, out of any function):
```
#begin
global {
    int x = 3;
    int y = 4;
}

int main() {
    y++;
    print(y); // "5"
    return 0;
}
#end
```
