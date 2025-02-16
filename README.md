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
