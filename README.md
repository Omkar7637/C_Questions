# C_Questions

Code demonstrates the difference between **global** and **local variables** in C.  

### Code Analysis:
```c
#include <stdio.h>

int a = 10;  // Global variable

void foo() {
    a++;  // Modifies the global variable 'a'
}

void bar() {
    printf("a: %d\n", a);  // Prints the global variable 'a'
}

void main() {
    int a = 30;  // Local variable inside main()
    
    foo();  // Increments global 'a' (10 -> 11)
    bar();  // Prints the global 'a' (11)
    
    printf("a: %d\n", a);  // Prints local 'a' (30)
}
```

### Expected Output:
```
a: 11
a: 30
```

### Explanation:
1. **Global vs Local Scope**:
   - `int a = 10;` (global) exists throughout the program.
   - `int a = 30;` (local in `main()`) **shadows** the global `a` inside `main()`.

2. **Function `foo()`**:
   - It modifies the **global** `a` (10 → 11).

3. **Function `bar()`**:
   - It prints the **global** `a` (which is now `11`).

4. **Final `printf()` in `main()`**:
   - It prints the **local** `a` (`30`), unaffected by `foo()`.

### Key Takeaways:
- `foo()` affects the **global** `a`, not the local one.
- `bar()` prints the **global** `a`, which was modified by `foo()`.
- `main()`'s `printf()` prints the **local** `a`, which remains `30`.

