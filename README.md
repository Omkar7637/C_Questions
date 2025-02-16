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

---

`arr[10]` and `10[arr]` are valid expressions in C, but their meanings differ:  

### 1. **`arr[10]` (Standard Notation)**  
   - `arr` is an array, and `arr[10]` accesses the element at index `10`.  
   - If `arr` is defined as `int arr[20];`, then `arr[10]` refers to the 11th element.

### 2. **`10[arr]` (Pointer Arithmetic Trick)**  
   - This works because **array indexing is commutative** in C.  
   - `arr[10]` is internally interpreted as `*(arr + 10)`.  
   - `10[arr]` is the same as `*(10 + arr)`, which still accesses index `10` of `arr`.

### Example:
```c
#include <stdio.h>

int main() {
    int arr[20] = {0}; // Declare an array with 20 elements, all initialized to 0
    arr[10] = 42;  // Assign value 42 to the 11th element
    
    printf("%d\n", arr[10]);  // Standard indexing
    printf("%d\n", 10[arr]);  // Unusual but valid indexing
    
    return 0;
}
```

### Output:
```
42
42
```

Even though `10[arr]` is valid, it's **not recommended** for readability reasons. Always use `arr[10]` for clarity.
