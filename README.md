# C_Questions
In C, format specifiers are used in functions like `printf` and `scanf` to define the type of data being handled. Below is a categorized list of format specifiers:

---

### **1. Integer Types**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%d` or `%i` | `int` | Signed decimal integer |
| `%u` | `unsigned int` | Unsigned decimal integer |
| `%hd` | `short int` | Signed short integer |
| `%hu` | `unsigned short int` | Unsigned short integer |
| `%ld` | `long int` | Signed long integer |
| `%lu` | `unsigned long int` | Unsigned long integer |
| `%lld` | `long long int` | Signed long long integer |
| `%llu` | `unsigned long long int` | Unsigned long long integer |
| `%Id` | `ptrdiff_t` | Integer type for pointer difference (MSVC specific) |
| `%I64d` | `__int64` | 64-bit integer (MSVC specific) |

---

### **2. Floating-Point Types**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%f` | `float`, `double` | Decimal floating point (e.g., `3.14`) |
| `%lf` | `double` | Double precision floating point |
| `%Lf` | `long double` | Extended precision floating point |
| `%e` or `%E` | `float`, `double` | Scientific notation (e.g., `3.14e+2`) |
| `%g` or `%G` | `float`, `double` | Shortest representation of `%f` or `%e` |

---

### **3. Character and String Types**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%c` | `char` | Single character |
| `%s` | `char*` | String (null-terminated) |

---

### **4. Pointer Type**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%p` | `void*` | Pointer address |

---

### **5. Miscellaneous**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%%` | - | Prints `%` symbol |

---

### **6. Format Specifiers for Size Compatibility**
| Specifier | Type | Description |
|-----------|------|-------------|
| `%hhd` | `signed char` | Signed 8-bit integer |
| `%hhu` | `unsigned char` | Unsigned 8-bit integer |
| `%zd` | `size_t` | Used for `size_t` (unsigned integral type) |

Your error message suggests using `%lld`, `%Id`, or `%I64d`, indicating that your argument is of type `unsigned __int64`, which requires a larger format specifier than `%d`.

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

---

Here’s a simple C program demonstrating the return values of `scanf` and `printf`:  

### **Code:**
```c
#include <stdio.h>

int main() {
    int num;
    
    // printf returns the number of characters printed
    int printf_ret = printf("Enter a number: ");
    
    // scanf returns the number of successfully read inputs
    int scanf_ret = scanf("%d", &num);
    
    // Display the return values
    printf("\nprintf returned: %d\n", printf_ret);
    printf("scanf returned: %d\n", scanf_ret);

    return 0;
}
```

### **Expected Output (Example Input: `25`)**
```
Enter a number: 25

printf returned: 15
scanf returned: 1
```

### **Explanation:**
1. **`printf` Return Value:**  
   - Returns the number of characters successfully printed.  
   - `"Enter a number: "` has 15 characters (excluding `\0`), so `printf` returns **15**.

2. **`scanf` Return Value:**  
   - Returns the number of successfully read inputs.  
   - Since `%d` expects an integer and we enter `25`, it reads **1** value successfully and returns **1**.  
   - If input is invalid (e.g., entering a letter instead of a number), `scanf` may return `0` or `EOF` on failure.

---

```c
#include <stdio.h>  // Include standard input-output library

int main() {
    int a = 65;  // Declare an integer variable 'a' and assign it the value 65

    char b = (char)a;  // Explicitly typecast 'a' to a character and store it in 'b'

    printf("%c\n", b);  // Print 'b' as a character using %c format specifier

    return 0;  // Return 0 to indicate successful execution
}
```

---

### **Explanation:**
1. **Variable Declaration (`int a = 65;`)**
   - We declare an integer `a` and assign it the value **65**.
   - In the ASCII table, **65** represents the character **'A'**.

2. **Typecasting (`char b = (char)a;`)**
   - The integer **65** is typecast to a `char` type.
   - The ASCII character corresponding to **65** is **'A'**.
   - Now, `b` holds the character **'A'**.

3. **Printing the Character (`printf("%c\n", b);`)**
   - `%c` is used to print a **character**.
   - Since `b` holds **'A'**, the output will be:
     ```
     A
     ```

4. **Return Statement (`return 0;`)**
   - Indicates that the program executed successfully.

---

### **Expected Output:**
```
A
```

This demonstrates **explicit typecasting**, where an `int` value is converted into a `char` based on its ASCII representation.

---

```c
#include <stdio.h>  // Include standard input-output library

#define NUM(x) x+x  // Macro definition: Expands as x + x (without parentheses)

int main() {
    int x = 10;  // Declare an integer variable x and assign it the value 10

    // The macro expands as: NUM(x) -> x + x, so it becomes: 
    // printf("%d", 10 + 10 / 2);
    // Due to operator precedence, division (/) happens first: 10 / 2 = 5
    // So the final expression becomes: 10 + 5 = 15
    printf("%d", NUM(x) / 2);

    return 0;
}
```

---

### **Explanation:**
1. **Macro Expansion (`#define NUM(x) x+x`)**
   - This macro expands `NUM(x)` as `x + x` (without parentheses).
   - If `x = 10`, `NUM(x)` expands to `10 + 10`.

2. **Expression in `printf` (`NUM(x)/2`)**
   - The macro expands first:  
     ```c
     printf("%d", x + x / 2);
     ```
   - Operator precedence rules apply:  
     - Division (`/`) has **higher precedence** than addition (`+`).
     - `x / 2` executes first → `10 / 2 = 5`.
     - Then `x + 5` → `10 + 5 = 15`.

3. **Output:**
   ```
   15
   ```

---

### **Fix to Avoid Unexpected Behavior**
To ensure the macro works as expected, always use **parentheses** in macro definitions:
```c
#define NUM(x) ((x) + (x))  // Proper macro definition with parentheses
```
This prevents unintended operator precedence issues.

--- 

---

## **1. Macro Expansion and Operator Precedence**
```c
#include <stdio.h>

#define SQUARE(x) x * x  // Macro without parentheses

int main() {
    int a = 4;
    printf("%d\n", SQUARE(a + 1));  // Expands to a + 1 * a + 1
    return 0;
}
```
### **Explanation:**
- **Macro Expansion:** `SQUARE(a + 1)` expands to `a + 1 * a + 1`, not `(a + 1) * (a + 1)`.
- **Operator Precedence:** `*` has higher precedence than `+`, so it becomes:
  ```
  a + (1 * a) + 1  => 4 + (1 * 4) + 1 = 9
  ```
- **Fix:** Always enclose macros in parentheses:
  ```c
  #define SQUARE(x) ((x) * (x))
  ```

✅ **Output:** `9` (instead of expected `25`)

---

## **2. Implicit Type Conversion**
```c
#include <stdio.h>

int main() {
    char c = 255;        // Signed char (-128 to 127)
    unsigned char uc = 255;  // Unsigned (0 to 255)

    if (c == uc)
        printf("Equal\n");
    else
        printf("Not Equal\n");

    return 0;
}
```
### **Explanation:**
- `char c = 255;` is stored as `-1` (due to sign extension in most compilers).
- `unsigned char uc = 255;` remains `255`.
- `if (c == uc)` → **comparison between signed and unsigned**.
- Since `-1 != 255`, the result is **"Not Equal"**.

✅ **Output:** `"Not Equal"`

---

## **3. Undefined Behavior - Integer Overflow**
```c
#include <stdio.h>

int main() {
    int x = 2147483647; // Max value for signed int
    x = x + 1;
    printf("%d\n", x);
    return 0;
}
```
### **Explanation:**
- `int` has a max value of `2147483647` (for 32-bit systems).
- `x + 1` overflows and results in **undefined behavior**.
- In most compilers, it wraps around to `-2147483648` (two's complement representation).

✅ **Output (on most systems):** `-2147483648` (but **undefined behavior**)

---

## **4. String Manipulation - Pointer Modification**
```c
#include <stdio.h>

int main() {
    char *str = "Hello";  // String literal stored in read-only memory
    str[0] = 'M';  // Trying to modify a string literal
    printf("%s\n", str);
    return 0;
}
```
### **Explanation:**
- `"Hello"` is stored in a **read-only** memory section.
- Modifying it (`str[0] = 'M'`) **causes segmentation fault**.

✅ **Output:** **Segmentation fault (runtime error)**

✔ **Fix:** Use a `char` array instead:
```c
char str[] = "Hello";  // Modifiable array
```
Your test result shows that `"Hello"` **was modifiable**, and instead of a segmentation fault, the program successfully printed `"Mello"`. This behavior depends on the compiler and execution environment.

### **Why Did It Work on Your System?**
1. **Compiler-Specific Behavior**:  
   - Some compilers store string literals in **modifiable** memory, while others place them in **read-only** sections.
   - Microsoft's MSVC (Visual Studio) sometimes allows modification of string literals due to historical reasons and backward compatibility.

2. **Undefined Behavior** (UB):  
   - The C standard **does not guarantee** that string literals are modifiable.
   - While some compilers let you modify them, others **crash with segmentation faults**.

### **Conclusion**
- **Even though it worked in your case, modifying a string literal is still undefined behavior.**
- **Portable Fix:**
  ```c
  char str[] = "Hello";  // Stored in stack, safe to modify
  str[0] = 'M';
  printf("%s\n", str);  // Prints "Mello"
  ```
- **Safer Alternative:**
  ```c
  char *str = strdup("Hello");  // Allocates modifiable memory
  str[0] = 'M';
  printf("%s\n", str);
  free(str);  // Prevent memory leak
  ```

Your example highlights how **compiler behavior can influence UB outcomes**, but it's always best to follow **strictly defined C standards** for portability. 🚀

---

## **5. Sizeof and Arrays**
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d\n", sizeof(arr) / sizeof(arr[0])); // Number of elements
    return 0;
}
```
### **Explanation:**
- `sizeof(arr)` returns **total array size** (`5 * 4 = 20` bytes).
- `sizeof(arr[0])` returns **size of one element** (`4` bytes).
- `sizeof(arr) / sizeof(arr[0]) = 20 / 4 = 5`.

✅ **Output:** `5` (correct array length)

---

## **6. Macro with Return Values**
```c
#include <stdio.h>

#define INCREMENT(x) x+1  // No parentheses

int main() {
    int a = 5;
    printf("%d\n", 2 * INCREMENT(a));
    return 0;
}
```
### **Explanation:**
- **Macro Expansion:** `2 * INCREMENT(a)` expands to:
  ```
  2 * a + 1  => (2 * 5) + 1 = 11
  ```
  Instead of `(2 * (5 + 1)) = 12`.

✔ **Fix:** Use parentheses:
```c
#define INCREMENT(x) ((x) + 1)
```

✅ **Output:** `11` (instead of expected `12`)

---

## **7. Pointer Arithmetic**
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    printf("%d\n", 2[arr]);  
    return 0;
}
```
### **Explanation:**
- `arr[2]` is equivalent to `*(arr + 2)`.
- **Array indexing works both ways:** `2[arr]` is valid and **same as `arr[2]`**.
- So, it prints `30`.

✅ **Output:** `30`

---

## **8. Dangling Pointers**
```c
#include <stdio.h>
#include <stdlib.h>

int* fun() {
    int x = 10;
    return &x;  // Returning address of a local variable
}

int main() {
    int *p = fun();
    printf("%d\n", *p);  // Undefined behavior
    return 0;
}
```
### **Explanation:**
- `x` is a **local variable**, which gets destroyed after `fun()` returns.
- `p` now holds a **dangling pointer** (invalid memory address).
- Dereferencing `*p` leads to **undefined behavior**.

✔ **Fix:** Allocate memory dynamically:
```c
int* fun() {
    int *x = malloc(sizeof(int));
    *x = 10;
    return x;
}
```

✅ **Output:** **Undefined behavior (may crash)**

---

### **Summary of Issues and Fixes**
| **Issue**                      | **Error Type**            | **Fix** |
|--------------------------------|-------------------------|--------|
| Macro Expansion (SQUARE)       | Operator Precedence     | Use parentheses in macro |
| Implicit Type Conversion       | Signed vs Unsigned      | Use explicit type casting |
| Integer Overflow               | Undefined Behavior      | Use `unsigned int` or `long long` |
| String Literal Modification    | Segmentation Fault      | Use `char str[]` instead of `char*` |
| `sizeof` on Array              | Misuse of `sizeof`      | Correct division method |
| Macro Without Parentheses      | Wrong Calculation       | Add parentheses in macro |
| `arr[2]` vs `2[arr]`           | Unusual Pointer Syntax  | Both are valid |
| Returning Local Address        | Dangling Pointer        | Use `malloc()` for dynamic memory |

---

Here are **more tricky C questions** with **code, inline comments, and separate explanations** to help you understand edge cases in C programming.

---

## **1. Pointer Arithmetic - Unexpected Output**
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *p = arr;
    
    printf("%d\n", *p++);  // What gets printed?
    return 0;
}
```
### **Explanation:**
- `*p++` **dereferences `p` first**, then increments it.
- So, `*p++` prints `10`, **then moves to `arr[1]` (20)**.

✅ **Output:** `10`

---

## **2. Size of Pointer vs Size of Array**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("%lu\n", sizeof(arr) / sizeof(ptr));
    return 0;
}
```
### **Explanation:**
- `sizeof(arr) = 20` (on a 32-bit system where `int` is 4 bytes).
- `sizeof(ptr) = 4` (since `ptr` is a pointer, not an array).
- `sizeof(arr) / sizeof(ptr) = 20 / 4 = 5` **(incorrect expectation)**.
- It **should** have been `sizeof(arr) / sizeof(arr[0])`.

✅ **Output:** `5` (if mistakenly dividing by `ptr`, it would be `5 / 1 = 5`)

Your code has a mistake in the `printf` statement. You are dividing `sizeof(arr)` by `sizeof(ptr)`, which is incorrect. It should be:

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("%lu\n", sizeof(arr) / sizeof(arr[0])); // Corrected
    return 0;
}
```

### Explanation:
- `sizeof(arr)`: Total size of the array (20 bytes for `int[5]` on a 32-bit system).
- `sizeof(arr[0])`: Size of one `int` (4 bytes).
- Correct division: `sizeof(arr) / sizeof(arr[0]) = 20 / 4 = 5`.

### Issue with `sizeof(ptr)`:
- `sizeof(ptr)` gives the size of a pointer (4 bytes on a 32-bit system, 8 bytes on a 64-bit system).
- `sizeof(arr) / sizeof(ptr)` would give `20 / 4 = 5` (on a 32-bit system) or `20 / 8 = 2` (on a 64-bit system), which is incorrect in context.

#### Correct ✅ Output:
```
5
```

---

## **3. Precedence of Bitwise and Logical Operators**
```c
#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    if (a & b && c)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
```
### **Explanation:**
- `a & b` → `1 & 2` → `0` (bitwise AND).
- `0 && c` → `0 && 3` → `0` (logical AND).
- Since the condition is `0`, **"False" is printed**.

✅ **Output:** `"False"`

---

## **4. Null Character in String**
```c
#include <stdio.h>

int main() {
    char str[10] = "Hello";
    printf("%lu\n", sizeof(str));
    return 0;
}
```
### **Explanation:**
- `str` is an array of size `10`, but `"Hello"` only occupies **6** (`5 chars + '\0'`).
- `sizeof(str)` gives **total array size**, not string length.

✅ **Output:** `10`

---

## **5. Unexpected Integer Promotion**
```c
#include <stdio.h>

int main() {
    char c = 127;
    c += 1;
    printf("%d\n", c);
    return 0;
}
```
### **Explanation:**
- `char` is **signed** by default (`-128` to `127`).
- `127 + 1` overflows, wrapping around to `-128`.

✅ **Output:** `-128`

---

## **6. Post-Increment in Function Calls**
```c
#include <stdio.h>

void fun(int x) {
    printf("%d\n", x);
}

int main() {
    int a = 5;
    fun(a++);
    printf("%d\n", a);
    return 0;
}
```
### **Explanation:**
- `fun(a++)` passes `5`, but `a` **increments after function call**.
- Then, `printf("%d\n", a);` prints `6`.

✅ **Output:**  
```
5
6
```

---

## **7. Dangling Pointer with Malloc**
```c
#include <stdio.h>
#include <stdlib.h>

int* fun() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    return ptr;
}

int main() {
    int *p = fun();
    free(p);  // Memory freed
    printf("%d\n", *p);  // What happens?
    return 0;
}
```
### **Explanation:**
- `p` points to freed memory.
- Dereferencing `*p` results in **undefined behavior**.

✅ **Output:** **Undefined behavior (may crash)**

✔ **Fix:** Set `p = NULL` after `free(p);`

---

## **8. Reverse Loop Trap**
```c
#include <stdio.h>

int main() {
    int i;
    for (i = 10; i >= 0; i--) {
        printf("%d ", i);
    }
    return 0;
}
```
### **Explanation:**
- `i` starts from `10` and **goes to `0`**.
- No infinite loop since `i` reaches `-1` and exits.

✅ **Output:**  
```
10 9 8 7 6 5 4 3 2 1 0
```

---

## **9. Misuse of `sizeof` on String Literal**
```c
#include <stdio.h>

int main() {
    printf("%lu\n", sizeof("Hello"));
    return 0;
}
```
### **Explanation:**
- `"Hello"` **is a string literal, not an array**.
- `sizeof("Hello")` **includes the null character (`\0`)**.
- `"Hello"` has `5` characters + `1` null terminator.

✅ **Output:** `6`

---

## **10. Function Pointer Confusion**
```c
#include <stdio.h>

void hello() {
    printf("Hello, World!\n");
}

int main() {
    void (*func)() = hello;  // Function pointer
    (*func)();  // Calling the function
    return 0;
}
```
### **Explanation:**
- `func` holds the address of `hello`.
- `(*func)();` calls `hello()`.
- Works like **normal function calls**.

✅ **Output:** `"Hello, World!"`

---

## **11. Strange Integer Promotion**
```c
#include <stdio.h>

int main() {
    char a = 255;
    unsigned char b = 255;

    if (a == b)
        printf("Equal\n");
    else
        printf("Not Equal\n");

    return 0;
}
```
### **Explanation:**
- `char a = 255;` stores `-1` (signed char).
- `unsigned char b = 255;` stores `255`.
- `if (-1 == 255)` → **false**.

✅ **Output:** `"Not Equal"`

---

## **12. Static Variable Behavior**
```c
#include <stdio.h>

void counter() {
    static int count = 0;
    count++;
    printf("%d\n", count);
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```
### **Explanation:**
- `static int count = 0;` retains its value across function calls.
- Each call **increments `count` instead of resetting it**.

✅ **Output:**
```
1
2
3
```

---

## **13. Pointer to Constant Data**
```c
#include <stdio.h>

int main() {
    const int x = 10;
    int *ptr = &x;  // Can we modify `x` using `ptr`?
    *ptr = 20;
    printf("%d\n", x);
    return 0;
}
```
### **Explanation:**
- `const int x = 10;` means `x` **should not be modified**.
- **But** `int *ptr` removes `const` (compiler may warn).
- **Undefined behavior** occurs when modifying `x`.

✅ **Output:** **Undefined behavior**

✔ **Fix:** Use `const int *ptr = &x;`

---

### **Summary Table**
| **Issue**                          | **Error Type**            | **Fix** |
|------------------------------------|--------------------------|--------|
| `*p++` unexpected output           | Pointer arithmetic       | Understand precedence |
| `sizeof(arr) / sizeof(ptr)`         | Pointer vs array size    | Use `sizeof(arr) / sizeof(arr[0])` |
| `c += 1;` wraparound issue         | Integer promotion        | Use `unsigned char` |
| Post-increment in function calls   | Parameter passing        | Be aware of side effects |
| Freeing memory then accessing it   | Dangling pointer         | Set pointer to NULL |
| `char a = 255;` vs `unsigned char` | Signed vs unsigned       | Use explicit casting |

---

These **tricky C questions** test deep understanding of **pointers, macros, memory management, and operator precedence**.  


---
----

---

### **1. Tricky Macro Expansion**
```c
#include <stdio.h>

#define SQUARE(x) x*x 

int main() {
    int a = 5;
    int result = SQUARE(a+1); 
    printf("%d\n", result);
    return 0;
}
```

#### **Explanation:**
- The macro `SQUARE(x)` expands as `x*x` without parentheses.
- `SQUARE(a+1)` expands as `a+1*a+1`, which evaluates incorrectly due to operator precedence.
- Instead of `(a+1) * (a+1)`, it becomes `5 + 1 * 5 + 1 = 5 + 5 + 1 = 11`, not `36`.
- **Fix:** Use `#define SQUARE(x) ((x) * (x))` to ensure correct expansion.

✅ **Output (incorrect):** `11`  
✅ **Expected output with fix:** `36`

---

### **2. Difference Between Array and Pointer**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Size of array: %lu\n", sizeof(arr));
    printf("Size of pointer: %lu\n", sizeof(ptr));

    return 0;
}
```

#### **Explanation:**
- `sizeof(arr)`: Gives total size of the array (`5 * 4 = 20` on a 32-bit system).
- `sizeof(ptr)`: Gives size of a pointer (`4` bytes on a 32-bit system, `8` bytes on a 64-bit system).

✅ **Output on 32-bit system:**
```
Size of array: 20
Size of pointer: 4
```
✅ **Output on 64-bit system:**
```
Size of array: 20
Size of pointer: 8
```

---

### **3. Comma Operator in Loops**
```c
#include <stdio.h>

int main() {
    int i = 0, j = 5;
    
    while (i < 5, j > 0) {
        printf("i = %d, j = %d\n", i, j);
        i++;
        j--;
    }

    return 0;
}
```

#### **Explanation:**
- The comma operator evaluates both expressions but only considers the last one.
- `i < 5, j > 0` results in `j > 0` being used for the loop condition.
- The loop runs until `j == 0`, not `i == 5`.

✅ **Output:**
```
i = 0, j = 5
i = 1, j = 4
i = 2, j = 3
i = 3, j = 2
i = 4, j = 1
```

---

### **4. Pointer Arithmetic Confusion**
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    printf("%d\n", 2[arr]);  
    return 0;
}
```

#### **Explanation:**
- `arr[2]` is the same as `*(arr + 2)`.
- `2[arr]` is the same as `*(2 + arr)`, which also evaluates to `arr[2]`.
- So, `2[arr]` prints `30`.

✅ **Output:** `30`

---

### **5. Undefined Behavior in Post-Increment**
```c
#include <stdio.h>

int main() {
    int a = 5;
    printf("%d %d\n", a, a++);
    return 0;
}
```

#### **Explanation:**
- The order of evaluation is **undefined**.
- Some compilers might print `5 5`, others might print `5 6`.
- **Avoid modifying and using `a` in the same expression!**

✅ **Output:** Undefined (may vary).

---

### **6. Implicit Type Promotion**
```c
#include <stdio.h>

int main() {
    char c = 255;
    printf("%d\n", c + 1);
    return 0;
}
```

#### **Explanation:**
- `char c = 255;` stores `255` (which is `0xFF`).
- `c` is promoted to `int`, making `c + 1 = 256`.
- If `char` is signed, `c = -1`, so `c + 1 = 0`.

✅ **Output (Unsigned char):** `256`  
✅ **Output (Signed char):** `0`

---

### **7. Logical vs Bitwise Operators**
```c
#include <stdio.h>

int main() {
    int x = 2, y = 3;
    if (x & y)
        printf("Bitwise AND: True\n");
    if (x && y)
        printf("Logical AND: True\n");
    return 0;
}
```

#### **Explanation:**
- `x & y`: Performs **bitwise AND**, `2 & 3 = 2`, which is **non-zero (true)**.
- `x && y`: Performs **logical AND**, both are **non-zero (true)**.

✅ **Output:**
```
Bitwise AND: True
Logical AND: True
```

---

These are tricky C questions that test fundamental concepts like macros, pointer arithmetic, evaluation order, and implicit type promotion.

---
---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### **1. Pointers & `const`**
What will be the output of the following program?  

```c
#include <stdio.h>

int main() {
    const int i = 10;
    int *ptr = (int *)&i;
    *ptr = 20;

    printf("i = %d\n", i);
    printf("*ptr = %d\n", *ptr);

    return 0;
}
```
👉 **What will it print? Will it crash? UB?**  

---

### **2. Memory Allocation & Pointer Arithmetic**
What will happen when you run this code?  

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) 
        arr[i] = i + 1;

    free(arr);
    printf("%d\n", arr[2]);  // Accessing after free

    return 0;
}
```
👉 **Will it print a value, crash, or behave unpredictably?**

---

### **3. Function Pointers**
What does this code output?  

```c
#include <stdio.h>

void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }

int main() {
    void (*fp)();
    fp = fun1;
    fp();
    fp = fun2;
    fp();

    return 0;
}
```
👉 **Can function pointers be reassigned like this?**

---

### **4. Bitwise Operations**
What is the output of this bitwise trick?  

```c
#include <stdio.h>

int main() {
    int x = 5;  
    int y = x << 1 | x >> 1;
    
    printf("%d\n", y);
    return 0;
}
```
👉 **How does left and right shifting affect the value?**

---

### **5. Structure Padding & Memory Alignment**
How much memory will the following structure take?  

```c
#include <stdio.h>

struct test {
    char a;
    int b;
    short c;
};

int main() {
    printf("%lu\n", sizeof(struct test));
    return 0;
}
```
👉 **How does padding affect memory usage?**

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---

## **🔹 Level 1: Basics (Easy)**
### **1. What does this `printf` statement print?**
```c
#include <stdio.h>
int main() {
    printf("%d\n", sizeof(NULL));
    return 0;
}
```
👉 **A)** `4`  
👉 **B)** `8`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`

---

### **2. What will this code output?**
```c
#include <stdio.h>
int main() {
    char str[] = "Hello";
    char *p = str;
    p[0] = 'h';
    printf("%s\n", str);
    return 0;
}
```
👉 **A)** `hello`  
👉 **B)** `Hello`  
👉 **C)** `Segmentation Fault`  
👉 **D)** `Compiler Error`

---

## **🔹 Level 2: Pointers & Memory Management (Intermediate)**
### **3. What will be the output of the following program?**
```c
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr + 2;
    printf("%d\n", *(ptr++));
    printf("%d\n", *ptr);
    return 0;
}
```
👉 **A)** `3 3`  
👉 **B)** `3 4`  
👉 **C)** `2 3`  
👉 **D)** `Undefined Behavior`

---

### **4. What happens when you run this program?**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));
    *p = 42;
    free(p);
    printf("%d\n", *p);  // Accessing freed memory
    return 0;
}
```
👉 **A)** `42`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Garbage Value`  
👉 **D)** `Compiler Error`

---

## **🔹 Level 3: Embedded C & Linux System Programming (Advanced)**
### **5. In an Embedded System, what does `volatile` ensure?**
```c
volatile int flag;
```
👉 **A)** Optimized variable storage  
👉 **B)** Ensures hardware changes are visible  
👉 **C)** Improves execution speed  
👉 **D)** Allocates memory on the heap  

---

### **6. What will this Linux C program print?**
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID: %d\n", getpid());
    fork();
    printf("Hello\n");
    return 0;
}
```
👉 **A)** `PID: 12345` then `Hello` once  
👉 **B)** `PID: 12345` then `Hello` twice  
👉 **C)** `Compiler Error`  
👉 **D)** `Runs forever`

---

## **🔹 Level 4: Algorithms & Data Structures (Expert)**
### **7. What is the time complexity of this sorting algorithm?**
```c
void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```
👉 **A)** `O(n log n)`  
👉 **B)** `O(n^2)`  
👉 **C)** `O(n)`  
👉 **D)** `O(1)`

---

### **8. How many times will the function be called in this recursion?**
```c
#include <stdio.h>

void func(int n) {
    if (n == 0) return;
    printf("%d ", n);
    func(n / 2);
}

int main() {
    func(16);
    return 0;
}
```
👉 **A)** `4`  
👉 **B)** `5`  
👉 **C)** `6`  
👉 **D)** `8`

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---

## **🔹 Level 1: Basics**
### **1. What is the output of this program?**  
```c
#include <stdio.h>
int main() {
    int x = 5;
    printf("%d %d %d\n", x++, x++, ++x);
    return 0;
}
```
👉 **A)** `5 6 8`  
👉 **B)** `7 6 8`  
👉 **C)** `5 5 7`  
👉 **D)** `Undefined Behavior`

---

### **2. What happens in this code?**  
```c
#include <stdio.h>
int main() {
    char *str = "Hello";
    str[0] = 'h';
    printf("%s\n", str);
    return 0;
}
```
👉 **A)** Prints `hello`  
👉 **B)** Prints `Hello`  
👉 **C)** Segmentation fault  
👉 **D)** Compiler error  

---

## **🔹 Level 2: Pointers & Memory Management**  
### **3. What is the output?**  
```c
#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;
    printf("%d\n", *ptr++);
    printf("%d\n", *(ptr + 1));
    return 0;
}
```
👉 **A)** `10 20`  
👉 **B)** `10 30`  
👉 **C)** `20 30`  
👉 **D)** `Compiler Error`

---

### **4. What happens in this `malloc()` case?**  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 100;
    free(ptr);
    printf("%d\n", *ptr);
    return 0;
}
```
👉 **A)** Prints `100`  
👉 **B)** Prints `Garbage Value`  
👉 **C)** Segmentation Fault  
👉 **D)** Compiler Error  

---

## **🔹 Level 3: Function Pointers & Recursion**
### **5. What is printed by this function pointer?**  
```c
#include <stdio.h>

void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }

int main() {
    void (*fp)();
    fp = fun1;
    fp();
    fp = fun2;
    fp();
    return 0;
}
```
👉 **A)** `Fun1 Fun1`  
👉 **B)** `Fun1 Fun2`  
👉 **C)** `Fun2 Fun2`  
👉 **D)** `Compiler Error`  

---

### **6. How many times does `func()` execute?**  
```c
#include <stdio.h>

void func(int n) {
    if (n == 0) return;
    printf("%d ", n);
    func(n / 2);
}

int main() {
    func(16);
    return 0;
}
```
👉 **A)** `4`  
👉 **B)** `5`  
👉 **C)** `6`  
👉 **D)** `8`  

---

## **🔹 Level 4: Bitwise & Undefined Behavior**
### **7. What is the output?**  
```c
#include <stdio.h>

int main() {
    int x = 5;
    int y = x << 1 | x >> 1;
    printf("%d\n", y);
    return 0;
}
```
👉 **A)** `5`  
👉 **B)** `10`  
👉 **C)** `7`  
👉 **D)** `Undefined Behavior`  

---

### **8. Structure Padding - How much memory does this struct take?**  
```c
#include <stdio.h>

struct test {
    char a;
    int b;
    short c;
};

int main() {
    printf("%lu\n", sizeof(struct test));
    return 0;
}
```
👉 **A)** `7 bytes`  
👉 **B)** `12 bytes`  
👉 **C)** `8 bytes`  
👉 **D)** `None of the above`  

---

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---

## **🔹 String Manipulation**  

### **1. What is the output of this program?**  
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    if (str1 == str2)
        printf("Same\n");
    else
        printf("Different\n");
    return 0;
}
```
👉 **A)** `Same`  
👉 **B)** `Different`  
👉 **C)** Compiler Error  
👉 **D)** Undefined Behavior  

---

### **2. What does this `strcpy()` behavior lead to?**  
```c
#include <stdio.h>
#include <string.h>

int main() {
    char *ptr;
    strcpy(ptr, "C Programming");
    printf("%s\n", ptr);
    return 0;
}
```
👉 **A)** Prints `C Programming`  
👉 **B)** Segmentation Fault  
👉 **C)** Compiler Error  
👉 **D)** Undefined Behavior  

---

### **3. What is the output of this program?**  
```c
#include <stdio.h>

void modify(char str[]) {
    str[0] = 'X';
}

int main() {
    char str[] = "Hello";
    modify(str);
    printf("%s\n", str);
    return 0;
}
```
👉 **A)** `Xello`  
👉 **B)** `Hello`  
👉 **C)** `Segmentation Fault`  
👉 **D)** Compiler Error  

---

## **🔹 Memory Leaks**  

### **4. What happens in this memory allocation case?**  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int) * 5);
    p[0] = 10;
    p[1] = 20;
    free(p);
    printf("%d\n", p[1]);
    return 0;
}
```
👉 **A)** Prints `20`  
👉 **B)** Prints Garbage Value  
👉 **C)** Segmentation Fault  
👉 **D)** Compiler Error  

---

### **5. What happens if we call `free()` twice on the same pointer?**  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(10 * sizeof(int));
    free(ptr);
    free(ptr);
    return 0;
}
```
👉 **A)** Works fine  
👉 **B)** Segmentation Fault  
👉 **C)** Compiler Error  
👉 **D)** Undefined Behavior  

---

## **🔹 Advanced C Tricks**  

### **6. What will this program print?**  
```c
#include <stdio.h>

int main() {
    int x = 10;
    printf("%d %d %d\n", x, x++, ++x);
    return 0;
}
```
👉 **A)** `10 10 12`  
👉 **B)** `10 11 12`  
👉 **C)** `10 10 11`  
👉 **D)** Undefined Behavior  

---

### **7. What is the value of `x` after this operation?**  
```c
#include <stdio.h>

int main() {
    int x = 5;
    x = x++ + ++x;
    printf("%d\n", x);
    return 0;
}
```
👉 **A)** `11`  
👉 **B)** `12`  
👉 **C)** Undefined Behavior  
👉 **D)** `10`  

---

### **8. How many bytes does this struct take?**  
```c
#include <stdio.h>

struct myStruct {
    char a;
    int b;
    double c;
};

int main() {
    printf("%lu\n", sizeof(struct myStruct));
    return 0;
}
```
👉 **A)** `13 bytes`  
👉 **B)** `16 bytes`  
👉 **C)** `24 bytes`  
👉 **D)** `None of the above`  

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---

## **🔹 Function Pointers**  

### **1. What is the output of this program?**  
```c
#include <stdio.h>

void fun(int x) {
    printf("%d ", x);
}

int main() {
    void (*ptr)(int);
    ptr = fun;
    (*ptr)(10);
    ptr(20);
    return 0;
}
```
👉 **A)** `10 20`  
👉 **B)** `20 10`  
👉 **C)** Compiler Error  
👉 **D)** Undefined Behavior  

---

### **2. What is printed in this function pointer array example?**  
```c
#include <stdio.h>

void one() { printf("One\n"); }
void two() { printf("Two\n"); }
void three() { printf("Three\n"); }

int main() {
    void (*arr[3])() = {one, two, three};
    for (int i = 0; i < 3; i++)
        arr[i]();
    return 0;
}
```
👉 **A)** `One Two Three`  
👉 **B)** `One One One`  
👉 **C)** Segmentation Fault  
👉 **D)** Compiler Error  

---

### **3. What is the output of this callback function example?**  
```c
#include <stdio.h>

void callback(int (*fptr)(int, int), int a, int b) {
    printf("%d\n", fptr(a, b));
}

int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }

int main() {
    callback(add, 5, 10);
    callback(multiply, 5, 10);
    return 0;
}
```
👉 **A)** `15 50`  
👉 **B)** `50 15`  
👉 **C)** `5 10`  
👉 **D)** Compiler Error  

---

## **🔹 Recursion**  

### **4. What is the output of this recursive function?**  
```c
#include <stdio.h>

void fun(int n) {
    if (n == 0) return;
    printf("%d ", n);
    fun(n - 1);
    printf("%d ", n);
}

int main() {
    fun(3);
    return 0;
}
```
👉 **A)** `3 2 1 1 2 3`  
👉 **B)** `3 2 1`  
👉 **C)** `1 2 3 3 2 1`  
👉 **D)** Compiler Error  

---

### **5. What is the output of this indirect recursion?**  
```c
#include <stdio.h>

void funB(int n);

void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funA(n / 2);
    }
}

int main() {
    funA(10);
    return 0;
}
```
👉 **A)** `10 9 4 3 1`  
👉 **B)** `10 9 4 3 2 1`  
👉 **C)** `10 9 4 3 1 2`  
👉 **D)** `10 9 4 2 1`  

---

### **6. What happens in this recursive factorial program?**  
```c
#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    printf("%d\n", fact(5));
    return 0;
}
```
👉 **A)** `120`  
👉 **B)** `5`  
👉 **C)** `6`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Bitwise Operations**  

### **7. What is the result of this bitwise AND operation?**  
```c
#include <stdio.h>

int main() {
    int a = 5, b = 3;
    printf("%d\n", a & b);
    return 0;
}
```
👉 **A)** `1`  
👉 **B)** `5`  
👉 **C)** `3`  
👉 **D)** `2`  

---

### **8. What is the output of this bitwise XOR operation?**  
```c
#include <stdio.h>

int main() {
    int a = 7, b = 9;
    printf("%d\n", a ^ b);
    return 0;
}
```
👉 **A)** `14`  
👉 **B)** `2`  
👉 **C)** `10`  
👉 **D)** `None of the above`  

---

### **9. What happens in this left shift operation?**  
```c
#include <stdio.h>

int main() {
    int x = 5;
    printf("%d\n", x << 2);
    return 0;
}
```
👉 **A)** `5`  
👉 **B)** `20`  
👉 **C)** `10`  
👉 **D)** `15`  

---

### **10. What is the output of this bitwise NOT operation?**  
```c
#include <stdio.h>

int main() {
    int x = 5;
    printf("%d\n", ~x);
    return 0;
}
```
👉 **A)** `-6`  
👉 **B)** `5`  
👉 **C)** `6`  
👉 **D)** `-5`  

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---

## **🔹 Macros**  

### **1. What is the output of this macro expansion?**  
```c
#include <stdio.h>

#define SQUARE(x) x * x

int main() {
    int a = 5;
    printf("%d\n", SQUARE(a + 1));
    return 0;
}
```
👉 **A)** `36`  
👉 **B)** `25`  
👉 **C)** `11`  
👉 **D)** `Compiler Error`  

---

### **2. What is the result of this preprocessor directive?**  
```c
#include <stdio.h>

#define MULTIPLY(a, b) a * b

int main() {
    printf("%d\n", MULTIPLY(3 + 2, 4 + 1));
    return 0;
}
```
👉 **A)** `25`  
👉 **B)** `20`  
👉 **C)** `15`  
👉 **D)** `Compiler Error`  

---

### **3. What happens in this token-pasting macro?**  
```c
#include <stdio.h>

#define CONCAT(a, b) a##b

int main() {
    int xy = 10;
    printf("%d\n", CONCAT(x, y));
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `Compiler Error`  
👉 **C)** `Undefined Behavior`  
👉 **D)** `None of the above`  

---

## **🔹 Inline Assembly (GCC - x86)**  

### **4. What is the output of this inline assembly program?**  
```c
#include <stdio.h>

int main() {
    int a = 10, b = 5, result;
    
    __asm__("addl %%ebx, %%eax;"
            : "=a"(result)
            : "a"(a), "b"(b));

    printf("%d\n", result);
    return 0;
}
```
👉 **A)** `15`  
👉 **B)** `10`  
👉 **C)** `5`  
👉 **D)** `Undefined Behavior`  

---

### **5. What does this inline assembly snippet do?**  
```c
#include <stdio.h>

int main() {
    int x = 7, y;
    
    __asm__("shl $1, %1; mov %1, %0;"
            : "=r"(y)
            : "r"(x));
    
    printf("%d\n", y);
    return 0;
}
```
👉 **A)** `14`  
👉 **B)** `7`  
👉 **C)** `1`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Tricky Pointer Arithmetic**  

### **6. What is the output of this pointer increment operation?**  
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    printf("%d\n", *(++ptr));
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `20`  
👉 **C)** `30`  
👉 **D)** `Compiler Error`  

---

### **7. What happens in this pointer subtraction example?**  
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = &arr[4];
    int *p2 = &arr[0];

    printf("%ld\n", p1 - p2);
    return 0;
}
```
👉 **A)** `4`  
👉 **B)** `5`  
👉 **C)** `1`  
👉 **D)** `Compiler Error`  

---

### **8. What is printed by this void pointer arithmetic example?**  
```c
#include <stdio.h>

int main() {
    void *ptr;
    int x = 10;
    ptr = &x;
    
    printf("%d\n", *(int *)ptr);
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `Garbage Value`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

### **9. What is the output of this complex pointer arithmetic?**  
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *p = arr;
    int **q = &p;

    *q = *q + 2;

    printf("%d\n", **q);
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `20`  
👉 **C)** `30`  
👉 **D)** `Compiler Error`  

---

### **10. What happens in this pointer cast operation?**  
```c
#include <stdio.h>

int main() {
    int x = 512;
    char *ptr = (char *)&x;

    printf("%d\n", *ptr);
    return 0;
}
```
👉 **A)** `0`  
👉 **B)** `2`  
👉 **C)** `512`  
👉 **D)** `Compiler Error`  

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---

## **🔹 Struct Padding & Alignment**  

### **1. What will be the size of the following struct?**  
```c
#include <stdio.h>

struct A {
    char c;
    int i;
    double d;
};

int main() {
    printf("%lu\n", sizeof(struct A));
    return 0;
}
```
👉 **A)** `16`  
👉 **B)** `24`  
👉 **C)** `32`  
👉 **D)** `Compiler Dependent`  

---

### **2. What will be the output of this struct alignment test?**  
```c
#include <stdio.h>

struct B {
    char a;
    short b;
    int c;
};

int main() {
    printf("%lu\n", sizeof(struct B));
    return 0;
}
```
👉 **A)** `7`  
👉 **B)** `8`  
👉 **C)** `12`  
👉 **D)** `6`  

---

### **3. What happens if we force-packed alignment?**  
```c
#include <stdio.h>
#pragma pack(1)

struct C {
    char a;
    int b;
};

int main() {
    printf("%lu\n", sizeof(struct C));
    return 0;
}
```
👉 **A)** `5`  
👉 **B)** `8`  
👉 **C)** `4`  
👉 **D)** `Compiler Error`  

---

### **4. What is the expected padding in the following struct?**  
```c
#include <stdio.h>

struct D {
    char x;
    double y;
    int z;
};

int main() {
    printf("%lu\n", sizeof(struct D));
    return 0;
}
```
👉 **A)** `13`  
👉 **B)** `16`  
👉 **C)** `24`  
👉 **D)** `Compiler Dependent`  

---

### **5. How to minimize padding in the following struct?**  
```c
struct E {
    char a;
    double b;
    short c;
    int d;
};
```
👉 **A)** Reorder as `{ double, int, short, char }`  
👉 **B)** Use `#pragma pack(1)`  
👉 **C)** Both A & B  
👉 **D)** Padding cannot be removed  

---

## **🔹 Undefined Behavior**  

### **6. What is the output of this uninitialized variable access?**  
```c
#include <stdio.h>

int main() {
    int x;
    printf("%d\n", x);
    return 0;
}
```
👉 **A)** `0`  
👉 **B)** `Garbage Value`  
👉 **C)** `Compiler Error`  
👉 **D)** `Segmentation Fault`  

---

### **7. What is the result of modifying a string literal?**  
```c
#include <stdio.h>

int main() {
    char *str = "Hello";
    str[0] = 'h';
    printf("%s\n", str);
    return 0;
}
```
👉 **A)** `"hello"`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

### **8. What happens in this signed integer overflow case?**  
```c
#include <stdio.h>
#include <limits.h>

int main() {
    int x = INT_MAX;
    printf("%d\n", x + 1);
    return 0;
}
```
👉 **A)** `-2147483648`  
👉 **B)** `Undefined Behavior`  
👉 **C)** `INT_MAX + 1`  
👉 **D)** `Compiler Error`  

---

### **9. What is the result of this pointer dereference?**  
```c
#include <stdio.h>

int main() {
    int *p = NULL;
    printf("%d\n", *p);
    return 0;
}
```
👉 **A)** `0`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

### **10. What is printed in this case of pointer aliasing?**  
```c
#include <stdio.h>

int main() {
    int x = 10;
    float *p = (float *)&x;
    
    printf("%f\n", *p);
    return 0;
}
```
👉 **A)** `10.000000`  
👉 **B)** `Garbage Value`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---

## **🔹 Bitwise Operations**  

### **1. What is the output of this XOR swap trick?**  
```c
#include <stdio.h>

int main() {
    int a = 5, b = 7;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%d %d\n", a, b);
    return 0;
}
```
👉 **A)** `5 7`  
👉 **B)** `7 5`  
👉 **C)** `0 0`  
👉 **D)** `Compiler Error`  

---

### **2. What does this bitwise expression evaluate to?**  
```c
#include <stdio.h>

int main() {
    int x = 7;  // 0111
    int y = x & ~(x - 1);
    printf("%d\n", y);
    return 0;
}
```
👉 **A)** `1`  
👉 **B)** `2`  
👉 **C)** `4`  
👉 **D)** `7`  

---

## **🔹 Function Pointers**  

### **3. What will be printed by this function pointer usage?**  
```c
#include <stdio.h>

void foo() {
    printf("Hello");
}

int main() {
    void (*ptr)();
    ptr = foo;
    (*ptr)();
    return 0;
}
```
👉 **A)** `Hello`  
👉 **B)** `Compiler Error`  
👉 **C)** `Garbage Value`  
👉 **D)** `Segmentation Fault`  

---

### **4. What happens in this case of function pointer misuse?**  
```c
#include <stdio.h>

void greet() {
    printf("Hi\n");
}

int main() {
    void (*ptr)();
    ptr = (void *)0x12345678;
    (*ptr)();
    return 0;
}
```
👉 **A)** `Hi`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Recursion**  

### **5. What is the output of this recursive function?**  
```c
#include <stdio.h>

void fun(int n) {
    if (n == 0) return;
    printf("%d ", n);
    fun(n--);
}

int main() {
    fun(3);
    return 0;
}
```
👉 **A)** `3 2 1`  
👉 **B)** `3`  
👉 **C)** `Infinite Loop`  
👉 **D)** `Compiler Warning/Error`  

---

### **6. What happens in this case of deep recursion?**  
```c
#include <stdio.h>

void recurse() {
    recurse();
}

int main() {
    recurse();
    return 0;
}
```
👉 **A)** `Infinite Loop`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Pointer Arithmetic**  

### **7. What will be printed in this pointer arithmetic example?**  
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;
    printf("%d\n", *(ptr + 2));
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `20`  
👉 **C)** `30`  
👉 **D)** `40`  

---

### **8. What happens in this invalid pointer arithmetic case?**  
```c
#include <stdio.h>

int main() {
    int *p = NULL;
    printf("%d\n", *(p + 1));
    return 0;
}
```
👉 **A)** `0`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Garbage Value`  
👉 **D)** `Undefined Behavior`  

---

### **9. What is the output of this pointer increment example?**  
```c
#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    printf("%p %p\n", p, p + 1);
    return 0;
}
```
👉 **A)** Same Address  
👉 **B)** Address Incremented by 1 Byte  
👉 **C)** Address Incremented by 4 Bytes  
👉 **D)** Compiler Error  

---

### **10. What is printed in this case of pointer aliasing?**  
```c
#include <stdio.h>

int main() {
    int x = 10;
    float *p = (float *)&x;
    
    printf("%f\n", *p);
    return 0;
}
```
👉 **A)** `10.000000`  
👉 **B)** `Garbage Value`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---

## **🔹 Struct Padding & Alignment**  

### **1. What is the size of this struct?**  
```c
#include <stdio.h>

struct A {
    char c;
    int i;
};

int main() {
    printf("%lu\n", sizeof(struct A));
    return 0;
}
```
👉 **A)** `5`  
👉 **B)** `8`  
👉 **C)** `12`  
👉 **D)** `16`  

---

### **2. What happens if we reorder struct members?**  
```c
#include <stdio.h>

struct B {
    char c1;
    double d;
    char c2;
};

int main() {
    printf("%lu\n", sizeof(struct B));
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `12`  
👉 **C)** `16`  
👉 **D)** `24`  

---

## **🔹 Undefined Behavior & Dangerous Code**  

### **3. What is the output of this dangling pointer access?**  
```c
#include <stdio.h>
#include <stdlib.h>

int* getMemory() {
    int x = 10;
    return &x;
}

int main() {
    int *p = getMemory();
    printf("%d\n", *p);
    return 0;
}
```
👉 **A)** `10`  
👉 **B)** `Garbage Value`  
👉 **C)** `Segmentation Fault`  
👉 **D)** `Undefined Behavior`  

---

### **4. What happens in this integer overflow case?**  
```c
#include <stdio.h>

int main() {
    unsigned int x = 0;
    x = x - 1;
    printf("%u\n", x);
    return 0;
}
```
👉 **A)** `-1`  
👉 **B)** `0`  
👉 **C)** `4294967295`  
👉 **D)** `Compiler Error`  

---

### **5. What happens in this case of modifying a string literal?**  
```c
#include <stdio.h>

int main() {
    char *s = "Hello";
    s[0] = 'X';
    printf("%s\n", s);
    return 0;
}
```
👉 **A)** `Xello`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Garbage Value`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Pointer Manipulations & Type Punning**  

### **6. What does this pointer casting do?**  
```c
#include <stdio.h>

int main() {
    int x = 0x12345678;
    char *p = (char*)&x;
    printf("%x\n", *p);
    return 0;
}
```
👉 **A)** `12`  
👉 **B)** `78`  
👉 **C)** `34`  
👉 **D)** `56`  

---

### **7. What happens in this function pointer misalignment?**  
```c
#include <stdio.h>

void hello() {
    printf("Hello\n");
}

int main() {
    void (*p)() = (void*)0x12345678;
    p();
    return 0;
}
```
👉 **A)** `Hello`  
👉 **B)** `Segmentation Fault`  
👉 **C)** `Garbage Value`  
👉 **D)** `Undefined Behavior`  

---

## **🔹 Recursive Macros & Preprocessor Madness**  

### **8. What is printed by this macro recursion?**  
```c
#include <stdio.h>

#define ADD(x, y) x + y
#define MULTIPLY(x, y) x * y

int main() {
    printf("%d\n", MULTIPLY(ADD(2, 3), 4));
    return 0;
}
```
👉 **A)** `20`  
👉 **B)** `14`  
👉 **C)** `Compiler Error`  
👉 **D)** `Garbage Value`  

---

### **9. What is printed in this tricky macro expansion?**  
```c
#include <stdio.h>

#define SQUARE(x) x * x

int main() {
    int a = 5;
    printf("%d\n", SQUARE(a+1));
    return 0;
}
```
👉 **A)** `36`  
👉 **B)** `25`  
👉 **C)** `Compiler Error`  
👉 **D)** `Garbage Value`  

---

## **🔹 Floating-Point Precision & Aliasing**  

### **10. What happens in this float-to-int aliasing?**  
```c
#include <stdio.h>

int main() {
    float f = 3.14;
    int *p = (int *)&f;
    printf("%d\n", *p);
    return 0;
}
```
👉 **A)** `3`  
👉 **B)** `Garbage Value`  
👉 **C)** `Compiler Error`  
👉 **D)** `Undefined Behavior`  

---
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

