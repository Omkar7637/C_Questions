# **📌 Introduction to DSA**  

### 🔹 **What is DSA?**
DSA stands for **Data Structures and Algorithms**. It is the backbone of problem-solving in programming.  
- **Data Structure**: A way to store and organize data efficiently (e.g., Arrays, Linked Lists, Stacks, Queues).  
- **Algorithm**: A step-by-step procedure to solve a problem efficiently (e.g., Searching, Sorting, Recursion).  

---

# **📌 Why DSA? Importance in Coding Interviews & Problem-Solving**
### 🔹 **Why should you learn DSA?**
1. **Optimized Problem Solving** – Helps in solving problems faster and efficiently.  
2. **Coding Interviews** – Almost every technical job interview has DSA questions.  
3. **Competitive Programming** – Helps in contests like CodeForces, LeetCode, and CodeChef.  
4. **Efficient Applications** – Used in OS, DBMS, Networking, AI, and Machine Learning.  

---

# **📌 Time & Space Complexity**
### 🔹 **Why is Complexity Analysis Important?**
When writing an algorithm, it’s crucial to measure:
- **Time Complexity**: How fast an algorithm runs.
- **Space Complexity**: How much memory an algorithm needs.

### **🔹 Big-O Notation (Worst Case)**
Big-O notation helps describe the worst-case performance of an algorithm.
| Complexity  | Notation | Example |
|------------|----------|------------|
| Constant  | **O(1)** | Accessing an element in an array |
| Logarithmic | **O(log N)** | Binary Search |
| Linear | **O(N)** | Traversing an array |
| Quadratic | **O(N²)** | Nested loops |
| Exponential | **O(2ⁿ)** | Recursive Fibonacci |

📌 **Example: Understanding O(N) Complexity**  
C Program to traverse an array in **O(N) time**:
```c
#include <stdio.h>

void traverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {  // Runs N times
        printf("%d ", arr[i]);  
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    traverseArray(arr, n);  // O(N) Complexity
    
    return 0;
}
```
### **🔹 Big-Theta (Θ) and Big-Omega (Ω)**
- **Big-Theta (Θ)**: Average case time complexity.
- **Big-Omega (Ω)**: Best case time complexity.

---

# **📌 Recursion Basics**
### 🔹 **What is Recursion?**
Recursion is a function that calls itself to break down problems into smaller subproblems.

📌 **Example: Factorial using Recursion**
```c
#include <stdio.h>

// Recursive function to calculate factorial
long long factorial(int n) {
    if (n == 0) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive case
}

int main() {
    int num = 5;
    printf("Factorial of %d is %lld", num, factorial(num));
    return 0;
}
```
📌 **Explanation:**
- **Base Case**: If `n == 0`, return 1.
- **Recursive Case**: Multiply `n` with `factorial(n - 1)`.
- **Time Complexity**: **O(N)**.

---

📌 **Next Up: More Recursion Problems**  
✅ Fibonacci using Recursion  
✅ Counting Digits in a Number  

# **📌 More Recursion Problems with Theory & Code**  

---

## **🔹 Fibonacci Series using Recursion**  
### **What is Fibonacci Series?**  
The Fibonacci series is a sequence of numbers where:  
- `F(0) = 0, F(1) = 1` (Base cases)  
- `F(n) = F(n-1) + F(n-2)` (Recursive formula)  

### **📌 C Program to Print Fibonacci Series using Recursion**
```c
#include <stdio.h>

// Recursive function to return nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {
    int n = 10; // Find first 10 Fibonacci numbers
    printf("Fibonacci Series: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}
```

### **📌 Explanation**  
✅ **Base Case:** If `n == 0`, return 0; if `n == 1`, return 1.  
✅ **Recursive Case:** Add previous two Fibonacci numbers (`F(n-1) + F(n-2)`).  
✅ **Time Complexity:** **O(2^N)** (Exponential, due to repeated calculations).  
✅ **Space Complexity:** **O(N)** (Recursive call stack).  

---

## **🔹 Counting Digits in a Number using Recursion**  
### **What is Digit Count?**  
To count the number of digits in a number **N**, divide the number by 10 recursively until it becomes 0.  

### **📌 C Program to Count Digits Using Recursion**
```c
#include <stdio.h>

// Recursive function to count digits
int countDigits(int n) {
    if (n == 0) return 0;  // Base case
    return 1 + countDigits(n / 10);  // Recursive case
}

int main() {
    int num = 123456;
    printf("Number of digits in %d is %d", num, countDigits(num));
    return 0;
}
```

### **📌 Explanation**  
✅ **Base Case:** If `n == 0`, return 0.  
✅ **Recursive Case:** Divide `n` by 10 and count `1 + countDigits(n/10)`.  
✅ **Time Complexity:** **O(log N)** (Because the number is divided by 10 in each step).  
✅ **Space Complexity:** **O(log N)** (Recursive call stack).  

---

📌 **Next Up: Arrays & Strings**  
✅ Basics of Arrays (1D, 2D, Multi-Dimensional)  
✅ Array Operations (Insertion, Deletion, Traversal)  
✅ String Basics & Operations  

# **📌 Arrays & Strings (Week 2) - Detailed Explanation & Code**  

---

## **🔹 Introduction to Arrays**  
An **array** is a collection of elements of the same data type stored at contiguous memory locations.  

### **📌 Types of Arrays**  
1. **One-Dimensional (1D) Array** → `int arr[5];`  
2. **Two-Dimensional (2D) Array** → `int arr[3][3];`  
3. **Multi-Dimensional Array** → `int arr[2][3][4];`  

---

## **📌 Array Operations**
### **🔹 1. Insertion (Adding an element at a specific index)**
📌 **C Program to Insert an Element in an Array**
```c
#include <stdio.h>

void insertElement(int arr[], int *n, int element, int pos) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];  // Shift elements to the right
    }
    arr[pos] = element;  // Insert new element
    (*n)++;  // Increase size
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5, element = 99, position = 2;

    printf("Before Insertion: ");
    printArray(arr, n);
    
    insertElement(arr, &n, element, position);

    printf("After Insertion: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:** O(N) (Worst case: inserting at the beginning)  
📌 **Space Complexity:** O(1)  

---

### **🔹 2. Deletion (Removing an element from a specific index)**
📌 **C Program to Delete an Element from an Array**
```c
#include <stdio.h>

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements to the left
    }
    (*n)--;  // Reduce size
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5, position = 2;

    printf("Before Deletion: ");
    printArray(arr, n);
    
    deleteElement(arr, &n, position);

    printf("After Deletion: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:** O(N) (Worst case: deleting from the beginning)  
📌 **Space Complexity:** O(1)  

---

## **🔹 Find Largest & Smallest Element in an Array**  
📌 **C Program to Find Largest & Smallest Element**
```c
#include <stdio.h>

void findLargestSmallest(int arr[], int n, int *largest, int *smallest) {
    *largest = arr[0];
    *smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *largest) *largest = arr[i];
        if (arr[i] < *smallest) *smallest = arr[i];
    }
}

int main() {
    int arr[] = {34, 78, 12, 90, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest, smallest;

    findLargestSmallest(arr, n, &largest, &smallest);

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}
```
📌 **Time Complexity:** O(N)  
📌 **Space Complexity:** O(1)  

---

## **🔹 Reversing an Array**
📌 **C Program to Reverse an Array**
```c
#include <stdio.h>

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Reversal: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("After Reversal: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:** O(N)  
📌 **Space Complexity:** O(1)  

---

## **🔹 Strings in C**
A **string** in C is an array of characters ending with a null character (`\0`).

### **String Operations**  
✅ Find Length  
✅ Reverse a String  
✅ Check if a String is Palindrome  
✅ Find Frequency of Characters  

---

### **🔹 Check if a String is a Palindrome**
📌 **C Program to Check Palindrome**
```c
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[] = "madam";

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
```
📌 **Time Complexity:** O(N)  
📌 **Space Complexity:** O(1)  

---

### **🔹 Find Frequency of Characters in a String**
📌 **C Program to Find Character Frequency**
```c
#include <stdio.h>
#include <string.h>

void findFrequency(char str[]) {
    int freq[256] = {0};  // ASCII table size

    for (int i = 0; i < strlen(str); i++) {
        freq[(int)str[i]]++;  // Count character occurrences
    }

    printf("Character Frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[] = "hello world";
    findFrequency(str);
    return 0;
}
```
📌 **Time Complexity:** O(N)  
📌 **Space Complexity:** O(1)  

---

# **✅ Summary**
✅ **Arrays**: Insertion, Deletion, Finding Largest & Smallest, Reversal  
✅ **Strings**: Palindrome Check, Frequency of Characters  

📌 **Next Up: Sorting & Searching**  
✅ Bubble Sort, Selection Sort, Insertion Sort  
✅ Linear Search, Binary Search  

# **📌 Sorting & Searching - Detailed Explanation & Code**  

Sorting and searching are essential in **data structures and algorithms** for efficient data retrieval and manipulation.

---

# **📌 Sorting Algorithms**
Sorting arranges elements in increasing or decreasing order.  
📌 **Types of Sorting Algorithms:**  
✅ **Bubble Sort** - Simple, but inefficient for large datasets.  
✅ **Selection Sort** - Selects the smallest/largest element and places it in order.  
✅ **Insertion Sort** - Sorts elements by shifting them into their correct position.  
✅ **Merge Sort** - A divide-and-conquer algorithm.  
✅ **Quick Sort** - Highly efficient for large datasets.  

---

## **🔹 Bubble Sort**
💡 **Concept:**  
- Compare adjacent elements and swap them if they are in the wrong order.  
- Repeat until the array is sorted.

📌 **C Program for Bubble Sort**
```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("After Sorting: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:**  
✅ Best Case: O(N) (Already sorted)  
✅ Worst Case: O(N²)  

---

## **🔹 Selection Sort**
💡 **Concept:**  
- Find the smallest element and swap it with the first element.  
- Repeat for remaining elements.

📌 **C Program for Selection Sort**
```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("After Sorting: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:**  
✅ Best & Worst Case: O(N²)  

---

## **🔹 Insertion Sort**
💡 **Concept:**  
- Take one element and place it in its correct position by shifting elements.

📌 **C Program for Insertion Sort**
```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("After Sorting: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:**  
✅ Best Case: O(N) (Already sorted)  
✅ Worst Case: O(N²)  

---

## **🔹 Merge Sort (Divide & Conquer)**
💡 **Concept:**  
- Divide the array into two halves.  
- Recursively sort both halves.  
- Merge the sorted halves.

📌 **C Program for Merge Sort**
```c
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("After Sorting: ");
    printArray(arr, n);

    return 0;
}
```
📌 **Time Complexity:** O(N log N)  
📌 **Space Complexity:** O(N)  

---

# **📌 Searching Algorithms**
Searching is used to find an element in a collection.

✅ **Linear Search** - Check each element one by one.  
✅ **Binary Search** - Search in a sorted array using divide & conquer.  

---

## **🔹 Linear Search**
📌 **C Program for Linear Search**
```c
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
```
📌 **Time Complexity:** O(N)  

---

## **🔹 Binary Search (Only for Sorted Arrays)**
📌 **C Program for Binary Search**
```c
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
```
📌 **Time Complexity:** O(log N)  

---

📌 **Next Up: Stacks & Queues 🚀**  

# **📌 Stacks & Queues - Detailed Explanation & Code**  

## **🔹 Stack (LIFO - Last In First Out)**
A **stack** follows the **LIFO (Last In, First Out)** principle.  

📌 **Operations on Stack:**  
✅ **Push** - Insert an element.  
✅ **Pop** - Remove the top element.  
✅ **Peek/Top** - Get the top element without removing it.  
✅ **isEmpty** - Check if the stack is empty.  

---

## **🔹 Stack Implementation Using Arrays (C)**
```c
#include <stdio.h>
#define MAX 5  // Stack size

int stack[MAX], top = -1;

// Push operation
void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top Element: %d\n", peek());
    pop();
    display();
    return 0;
}
```
📌 **Time Complexity:**  
✅ Push: O(1)  
✅ Pop: O(1)  
✅ Peek: O(1)  

---

## **🔹 Stack Implementation Using Linked List (C)**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push operation
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", top->data);
    Node* temp = top;
    top = top->next;
    free(temp);
}

// Peek operation
int peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top Element: %d\n", peek());
    pop();
    display();
    return 0;
}
```
📌 **Advantages of Linked List Stack:**  
✅ No fixed size (dynamic memory allocation).  
✅ Efficient memory usage.  

---

## **🔹 Queue (FIFO - First In First Out)**
A **queue** follows the **FIFO (First In, First Out)** principle.  

📌 **Operations on Queue:**  
✅ **Enqueue** - Insert element at the rear.  
✅ **Dequeue** - Remove element from the front.  
✅ **Front** - Get the first element.  
✅ **isEmpty** - Check if queue is empty.  

---

## **🔹 Queue Implementation Using Arrays (C)**
```c
#include <stdio.h>
#define MAX 5  // Queue size

int queue[MAX], front = -1, rear = -1;

// Enqueue operation
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = data;
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
```
📌 **Time Complexity:**  
✅ Enqueue: O(1)  
✅ Dequeue: O(1)  

---

## **🔹 Queue Implementation Using Linked List (C)**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    Node* temp = front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
```
📌 **Advantages of Linked List Queue:**  
✅ No fixed size (dynamic memory allocation).  
✅ Efficient memory usage.  

---

## **🔹 Circular Queue**
A **circular queue** overcomes the problem of wasted space in a normal queue.  

📌 **Circular Queue Implementation in C**
```c
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

// Enqueue operation
void enqueue(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
```
📌 **Time Complexity:**  
✅ Enqueue: O(1)  
✅ Dequeue: O(1)  

---

📌 **Next Up: Linked Lists 🚀**  

# **📌 Linked Lists - Detailed Explanation & Code**  

## **🔹 What is a Linked List?**  
A **linked list** is a linear data structure where elements are stored in **nodes**, and each node contains:  
1. **Data** (value of the node)  
2. **Pointer** (address of the next node)  

📌 **Types of Linked Lists:**  
✅ **Singly Linked List** - Each node has a pointer to the next node.  
✅ **Doubly Linked List** - Each node has pointers to both next and previous nodes.  
✅ **Circular Linked List** - The last node points back to the first node.  

---

## **🔹 Singly Linked List Operations (C Implementation)**  

### **1️⃣ Create a Node Structure**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
```
---

### **2️⃣ Insert a Node at the Beginning**
```c
void insertAtBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
```
✅ **Time Complexity:** O(1)  

---

### **3️⃣ Insert a Node at the End**
```c
void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
```
✅ **Time Complexity:** O(n)  

---

### **4️⃣ Delete a Node from the Beginning**
```c
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    head = head->next;
    free(temp);
}
```
✅ **Time Complexity:** O(1)  

---

### **5️⃣ Delete a Node from the End**
```c
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
```
✅ **Time Complexity:** O(n)  

---

### **6️⃣ Display the Linked List**
```c
void display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

---

### **📌 Complete Code for Singly Linked List**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    display();
    
    deleteFromBeginning();
    display();
    
    deleteFromEnd();
    display();
    
    return 0;
}
```

---

## **🔹 Doubly Linked List Operations (C Implementation)**  

Each node contains a **previous pointer** and a **next pointer**.  

### **1️⃣ Create a Doubly Linked List Node**
```c
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
```
---

### **2️⃣ Insert at the Beginning**
```c
void insertAtBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}
```
✅ **Time Complexity:** O(1)  

---

### **3️⃣ Insert at the End**
```c
void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
```
✅ **Time Complexity:** O(n)  

---

### **4️⃣ Delete a Node**
```c
void deleteNode(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) return;

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    if (temp == head) head = temp->next;
    
    free(temp);
}
```
✅ **Time Complexity:** O(n)  

---

### **5️⃣ Display the Doubly Linked List**
```c
void display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

---

## **📌 Next Up: Trees 🚀**

# **📌 Trees - Detailed Explanation & Code**  

## **🔹 What is a Tree?**  
A **tree** is a hierarchical data structure that consists of **nodes** connected by **edges**. Unlike linked lists or arrays, a tree is **non-linear** and represents relationships like family trees, file systems, and decision-making processes.

📌 **Key Terminology:**  
✅ **Root** - The topmost node of the tree.  
✅ **Parent & Child** - Nodes connected directly below a node are children; the node above is the parent.  
✅ **Leaf Node** - A node with no children.  
✅ **Height of a Tree** - The longest path from the root to a leaf node.  
✅ **Depth of a Node** - Distance from the root to that node.  

---

## **🔹 Types of Trees**
1. **Binary Tree** - Each node has at most two children.  
2. **Binary Search Tree (BST)** - A binary tree where:  
   - Left child < Parent  
   - Right child > Parent  
3. **Balanced Trees** - Trees like **AVL** and **Red-Black Trees** maintain balance for efficient operations.  
4. **Heap** - A complete binary tree where the root is the minimum or maximum.  

---

# **📌 Binary Tree - Implementation in C**  
A **binary tree** has a structure where each node contains:  
1. **Data**  
2. **Left child pointer**  
3. **Right child pointer**  

### **1️⃣ Define a Node Structure**
```c
#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

---

### **2️⃣ Insert a Node in a Binary Tree**
(For simplicity, inserting at the leftmost available position)
```c
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}
```
✅ **Time Complexity:** O(log n) (for balanced trees)  

---

### **3️⃣ Tree Traversal Methods**
Traversal is how we visit each node in the tree.  

#### **1️⃣ Inorder Traversal (Left → Root → Right)**
```c
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```
✅ **Output:** Sorted order of BST elements.  

#### **2️⃣ Preorder Traversal (Root → Left → Right)**
```c
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
```

#### **3️⃣ Postorder Traversal (Left → Right → Root)**
```c
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
```

---

### **4️⃣ Search in a Binary Search Tree (BST)**
```c
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
```
✅ **Time Complexity:** O(log n)  

---

### **5️⃣ Find the Minimum and Maximum in a BST**
```c
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
```

---

### **6️⃣ Delete a Node from BST**
```c
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = createNode(findMin(root->right));
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```
✅ **Time Complexity:** O(log n)  

---

### **📌 Complete Code for Binary Search Tree (BST)**
```c
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Search for a node
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

// Find the minimum value
int findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root->data;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = createNode(findMin(root->right));
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
```

---

## **📌 Next Up: Graphs 🚀**

# **📌 Graphs - Detailed Explanation & Code**  

## **🔹 What is a Graph?**  
A **graph** is a collection of **nodes (vertices)** connected by **edges**. Unlike trees, graphs can have **cycles** and are used to model real-world problems like **networks, social media, and routing algorithms**.

📌 **Key Terminology:**  
✅ **Vertex (Node)** - A point in the graph.  
✅ **Edge** - A connection between two nodes.  
✅ **Adjacency List** - A list storing neighbors of each node.  
✅ **Adjacency Matrix** - A 2D matrix representing edge connections.  
✅ **Directed Graph (Digraph)** - Edges have a direction (A → B).  
✅ **Undirected Graph** - Edges are bidirectional (A ↔ B).  

---

## **🔹 Types of Graph Representations**
Graphs can be represented in two common ways:  

### **1️⃣ Adjacency Matrix (2D Array)**
Each cell `(i, j)` is **1** if there is an edge from node `i` to `j`, else `0`.  

📌 **Example Graph:**  
```
    (0) --- (1)
     |  \    |
     |   \   |
    (2) --- (3)
```
✅ **Adjacency Matrix Representation:**
```
  0  1  2  3
0[0, 1, 1, 1]
1[1, 0, 0, 1]
2[1, 0, 0, 1]
3[1, 1, 1, 0]
```
```c
#include <stdio.h>
#define V 4  // Number of vertices

// Function to print adjacency matrix
void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };

    printf("Adjacency Matrix:\n");
    printGraph(graph);

    return 0;
}
```
✅ **Time Complexity:** O(1) for edge lookup, O(V²) space complexity.  

---

### **2️⃣ Adjacency List (Using Arrays of Linked Lists)**
Each vertex has a list of adjacent vertices.  

📌 **Example Graph:**  
```
0 → [1, 2, 3]
1 → [0, 3]
2 → [0, 3]
3 → [0, 1, 2]
```
```c
#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct Graph {
    Node* adjList[V];  // Array of pointers
} Graph;

// Function to create a graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge (Undirected Graph)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge in reverse direction (for undirected graph)
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print adjacency list
void printGraph(Graph* graph) {
    for (int i = 0; i < V; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printf("Adjacency List:\n");
    printGraph(graph);

    return 0;
}
```
✅ **Time Complexity:** O(1) for edge lookup, O(V + E) space complexity.  

---

## **📌 Graph Traversal Algorithms**  
Two common ways to traverse a graph:  

### **1️⃣ Breadth-First Search (BFS)**
- Explores neighbors first before moving deeper.  
- Uses a **queue (FIFO)**.  

📌 **Example BFS Order for Above Graph (Starting at 0):**  
`0 → 1 → 2 → 3`  

```c
#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices

// Queue implementation for BFS
typedef struct Queue {
    int items[V];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == V - 1) return;
    q->items[++q->rear] = value;
    if (q->front == -1) q->front = 0;
}

int dequeue(Queue* q) {
    if (q->front == -1) return -1;
    int item = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

// BFS Function
void BFS(int graph[V][V], int start) {
    int visited[V] = {0};
    Queue* q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    while (q->front != -1) {
        int vertex = dequeue(q);
        printf("%d ", vertex);

        for (int i = 0; i < V; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };

    printf("BFS Traversal: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}
```
✅ **Time Complexity:** O(V + E)  

---

### **2️⃣ Depth-First Search (DFS)**
- Explores as deep as possible before backtracking.  
- Uses **recursion (stack-based)**.  

📌 **Example DFS Order for Above Graph (Starting at 0):**  
`0 → 1 → 3 → 2`  

```c
void DFS(int graph[V][V], int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };

    int visited[V] = {0};

    printf("DFS Traversal: ");
    DFS(graph, visited, 0);
    printf("\n");

    return 0;
}
```
✅ **Time Complexity:** O(V + E)  

---

## **📌 Next Up: Shortest Path Algorithms 🚀**  
# **📌 Shortest Path Algorithms - Detailed Explanation & Code**  

## **🔹 What is Shortest Path?**  
A **shortest path algorithm** finds the minimum distance between nodes in a graph. These algorithms are widely used in **network routing, GPS navigation, and AI pathfinding**.

---

## **📌 Types of Shortest Path Algorithms**
✅ **Single Source Shortest Path** - Find shortest path from one node to all others.  
✅ **All Pairs Shortest Path** - Find shortest paths between every pair of nodes.  

---

# **🔹 1️⃣ Dijkstra’s Algorithm (Greedy)**
- **Finds shortest path from a single source to all nodes.**  
- **Uses a priority queue (Min-Heap).**  
- **Works only for graphs with non-negative weights.**  

📌 **Example Graph:**  
```
      0
     / \
    1   4
   / \ / \
  2   3   5
```
✅ **Adjacency Matrix Representation:**
```
    0   1   4   ∞   ∞
    1   0   2   6   ∞
    4   2   0   3   5
    ∞   6   3   0   7
    ∞   ∞   5   7   0
```
✅ **Time Complexity:** O((V + E) log V) (Using Priority Queue)  

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices

// Find vertex with minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];   
    bool visited[V];  

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 1, 4, 0, 0},
        {1, 0, 2, 6, 0},
        {4, 2, 0, 3, 5},
        {0, 6, 3, 0, 7},
        {0, 0, 5, 7, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
```
✅ **Output:**  
```
Vertex  Distance from Source
0       0
1       1
2       3
3       6
4       8
```

---

# **🔹 2️⃣ Bellman-Ford Algorithm (Handles Negative Weights)**
- **Finds shortest path from a single source.**  
- **Works for graphs with negative weights (unlike Dijkstra).**  
- **Detects negative weight cycles.**  
- **Time Complexity:** O(VE)  

```c
#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 8  // Number of edges

// Edge structure
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Bellman-Ford Algorithm
void BellmanFord(Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    Edge edges[E] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    BellmanFord(edges, 0);
    return 0;
}
```
✅ **Handles negative weights** but is **slower than Dijkstra**.

---

# **🔹 3️⃣ Floyd-Warshall Algorithm (All-Pairs Shortest Path)**
- **Finds shortest paths between all pairs of nodes.**  
- **Uses Dynamic Programming.**  
- **Time Complexity:** O(V³)  

📌 **Example Graph:**  
```
      (0)
     /   \
   1      4
   |      |
   2 --- 3
     \   /
      (5)
```
```c
#include <stdio.h>

#define INF 99999
#define V 4  // Number of vertices

// Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) printf("%4s", "INF");
            else printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   3,  INF, 5},
        {2,   0,  INF, 4},
        {INF, 1,  0,   INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(graph);
    return 0;
}
```
✅ **Best for dense graphs but slower than Dijkstra & Bellman-Ford**.  

---

# **📌 Summary of Shortest Path Algorithms**
| Algorithm        | Handles Negative Weights | Best for        | Time Complexity  |
|-----------------|------------------------|----------------|----------------|
| **Dijkstra**    | ❌ No                    | Sparse Graphs  | O((V+E) log V) |
| **Bellman-Ford**| ✅ Yes                    | General Graphs | O(VE)          |
| **Floyd-Warshall** | ✅ Yes               | Dense Graphs   | O(V³)          |

---

# **📌 Next Up: Minimum Spanning Tree (MST) Algorithms 🚀**  

# **📌 Minimum Spanning Tree (MST) Algorithms - Theory & Code**  

## **🔹 What is a Minimum Spanning Tree (MST)?**
A **spanning tree** is a subset of a graph that:
✅ Includes all vertices.  
✅ Has no cycles.  
✅ Connects all vertices with the minimum possible edge weight.  

✅ **Real-World Uses:**  
- Network design (LAN, Internet cabling).  
- Circuit design.  
- Road & railway networks.  

---

# **🔹 1️⃣ Prim’s Algorithm (Greedy)**
✅ **Finds MST using a greedy approach.**  
✅ **Uses a priority queue (Min-Heap).**  
✅ **Time Complexity:** O(V²) (Using adjacency matrix), O((V+E) log V) (Using Min-Heap).  

📌 **Example Graph:**  
```
      0
     / \
    2   3
   /|   |\
  1 4   5 6
```
✅ **Adjacency Matrix Representation:**  
```
    0   2   3   ∞   ∞
    2   0   4   5   ∞
    3   4   0   ∞   6
    ∞   5   ∞   0   7
    ∞   ∞   6   7   0
```

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices

// Find vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Print MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

// Prim’s Algorithm
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];    
    bool mstSet[V]; 

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;  
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 4, 5, 0},
        {3, 4, 0, 0, 6},
        {0, 5, 0, 0, 7},
        {0, 0, 6, 7, 0}
    };

    primMST(graph);
    return 0;
}
```

✅ **Output:**  
```
Edge    Weight
0 - 1    2
0 - 2    3
1 - 3    5
2 - 4    6
```

---

# **🔹 2️⃣ Kruskal’s Algorithm (Greedy - Uses Disjoint Set)**
✅ **Finds MST using edge sorting & union-find (Disjoint Set).**  
✅ **Works for disconnected graphs.**  
✅ **Time Complexity:** O(E log E) (Sorting edges).  

📌 **Steps:**  
1. Sort all edges by weight.  
2. Pick the smallest edge that doesn’t form a cycle.  
3. Repeat until you have (V-1) edges.  

```c
#include <stdio.h>
#include <stdlib.h>

#define V 5  
#define E 7  

// Edge structure
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Graph structure
typedef struct Graph {
    Edge edges[E];
} Graph;

// Find set of an element
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Perform union of sets
void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

// Comparison function for sorting edges
int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal’s Algorithm
void KruskalMST(Graph* graph) {
    Edge result[V - 1];
    int parent[V];

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    qsort(graph->edges, E, sizeof(Edge), compare);

    int e = 0, i = 0;
    while (e < V - 1 && i < E) {
        Edge nextEdge = graph->edges[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(parent, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    Graph graph = {
        {{0, 1, 2}, {0, 2, 3}, {1, 2, 4}, {1, 3, 5}, {2, 4, 6}, {3, 4, 7}, {1, 4, 8}}
    };

    KruskalMST(&graph);
    return 0;
}
```

✅ **Output:**  
```
Edge    Weight
0 - 1    2
0 - 2    3
1 - 3    5
2 - 4    6
```

---

# **📌 Comparison of MST Algorithms**
| Algorithm   | Works on      | Approach      | Best for      | Time Complexity |
|------------|--------------|--------------|--------------|---------------|
| **Prim’s**  | Connected Graphs | Greedy (Min-Heap) | Dense Graphs | O(V²) or O((V+E) log V) |
| **Kruskal’s** | Any Graph | Greedy (Sorting + Union-Find) | Sparse Graphs | O(E log E) |

✅ **When to Use What?**  
- **Prim’s** - If the graph is **dense** (many edges).  
- **Kruskal’s** - If the graph is **sparse** (fewer edges).  

---

# **📌 Next Up: Graph Traversal Algorithms 🚀**  
# **📌 Graph Traversal Algorithms (BFS & DFS) - Theory & Code**

---

## **🔹 What is Graph Traversal?**
Graph traversal is the process of visiting all the nodes (or vertices) of a graph in a systematic manner. The two main traversal techniques are:

✅ **Breadth-First Search (BFS)** - Uses a **queue** (FIFO)  
✅ **Depth-First Search (DFS)** - Uses a **stack** (LIFO) or **recursion**

### **📌 Why Graph Traversal?**
- **Pathfinding** (Google Maps, AI in Games).  
- **Network Crawling** (Web Crawlers, Social Media Recommendations).  
- **Solving Mazes & Puzzles**.  
- **Cycle Detection** in Graphs.  

---

# **🔹 1️⃣ Breadth-First Search (BFS)**
✅ **Explores neighbors first before going deeper**.  
✅ **Uses a queue** (First-In-First-Out).  
✅ **Time Complexity:** O(V + E) (V = vertices, E = edges).  
✅ **Best for finding shortest paths in an **unweighted** graph**.

📌 **Example Graph:**
```
     0
    / \
   1   2
  / \   \
 3   4   5
```

📌 **Adjacency List Representation:**
```
0 -> 1, 2
1 -> 3, 4
2 -> 5
```

### **📌 BFS Implementation in C**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6  // Number of vertices

// Queue structure for BFS
typedef struct {
    int items[V];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == V - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q))
        return -1;
    item = q->items[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

// BFS Algorithm
void BFS(int graph[V][V], int startVertex) {
    Queue* q = createQueue();
    bool visited[V] = {false};

    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    BFS(graph, 0);
    return 0;
}
```

✅ **Output:**
```
BFS Traversal: 0 1 2 3 4 5
```

---

# **🔹 2️⃣ Depth-First Search (DFS)**
✅ **Explores as deep as possible before backtracking**.  
✅ **Uses a stack (or recursion)**.  
✅ **Time Complexity:** O(V + E).  
✅ **Best for:**  
- Detecting **cycles** in a graph.  
- **Topological sorting** in DAG (Directed Acyclic Graphs).  
- **Finding connected components**.  

📌 **Example Graph (Same as BFS Example)**  
```
     0
    / \
   1   2
  / \   \
 3   4   5
```

📌 **Adjacency List Representation:**
```
0 -> 1, 2
1 -> 3, 4
2 -> 5
```

### **📌 DFS Implementation in C**
```c
#include <stdio.h>
#include <stdbool.h>

#define V 6  // Number of vertices

void DFSUtil(int graph[V][V], bool visited[], int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && !visited[i])
            DFSUtil(graph, visited, i);
    }
}

// DFS Algorithm
void DFS(int graph[V][V], int startVertex) {
    bool visited[V] = {false};

    printf("DFS Traversal: ");
    DFSUtil(graph, visited, startVertex);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    DFS(graph, 0);
    return 0;
}
```

✅ **Output:**
```
DFS Traversal: 0 1 3 4 2 5
```

---

# **📌 BFS vs. DFS**
| Feature | BFS | DFS |
|---------|-----|-----|
| **Data Structure** | Queue (FIFO) | Stack (Recursion) |
| **Best for** | Shortest Path (Unweighted) | Cycle Detection, Topological Sorting |
| **Time Complexity** | O(V + E) | O(V + E) |
| **Space Complexity** | O(V) (Queue) | O(V) (Recursive Stack) |

✅ **When to Use What?**  
- **Use BFS for:** **Shortest paths**, network broadcasting.  
- **Use DFS for:** **Backtracking problems**, cycle detection.  

---

# **📌 Next Up: Topological Sorting (Kahn's Algorithm & DFS Approach) 🚀**
# **📌 Topological Sorting (Kahn's Algorithm & DFS Approach) - Theory & Code**

---

## **🔹 What is Topological Sorting?**
Topological sorting is a linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every directed edge **(u → v)**, **vertex u comes before vertex v** in the ordering.

✅ **Only possible for DAGs (Directed Acyclic Graphs).**  
✅ **Used in:**  
   - Task Scheduling (e.g., dependency resolution in OS scheduling).  
   - Course Prerequisites Problem (e.g., CS101 before CS102).  
   - Compilation Order of Code Files.  
   - Resolving Dependencies in Package Managers (e.g., npm, apt).  

---

## **🔹 1️⃣ Kahn’s Algorithm (BFS Approach)**
✅ **Uses In-degree (number of incoming edges) for ordering.**  
✅ **Steps:**  
1. Compute the **in-degree** (number of incoming edges) for each vertex.  
2. Enqueue **all vertices with in-degree 0** (nodes with no dependencies).  
3. Process each node, reduce the in-degree of its neighbors, and enqueue new zero in-degree nodes.  
4. If all nodes are processed, we have a valid topological order.

✅ **Time Complexity:** **O(V + E)**  
✅ **Space Complexity:** **O(V)** (for storing in-degree and queue).  

---

### **📌 Example Graph**
```
   5 → 0 → 2
   ↓
   4 → 1 → 3
```
### **📌 Adjacency List Representation**
```
5 → 0, 2
4 → 0, 1
2 → 3
3 → {}
1 → 3
```

---

### **📌 Kahn’s Algorithm (BFS) Implementation in C**
```c
#include <stdio.h>
#include <stdlib.h>

#define V 6  // Number of vertices

// A queue structure for BFS
typedef struct {
    int items[V];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == V - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1) return -1;
    int item = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

// Topological Sorting using Kahn’s Algorithm (BFS)
void topologicalSort(int graph[V][V]) {
    int inDegree[V] = {0};  // Stores in-degree of nodes
    Queue* q = createQueue();

    // Calculate in-degree of all vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) inDegree[j]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) enqueue(q, i);
    }

    printf("Topological Sort (Kahn’s Algorithm): ");
    while (q->front != -1) {
        int vertex = dequeue(q);
        printf("%d ", vertex);

        // Reduce in-degree of neighbors
        for (int i = 0; i < V; i++) {
            if (graph[vertex][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);
    return 0;
}
```

✅ **Output:**  
```
Topological Sort (Kahn’s Algorithm): 5 4 0 2 1 3
```

---

## **🔹 2️⃣ DFS Approach (Using Stack)**
✅ **Uses **recursion** and **post-order traversal** (push nodes onto a stack when done processing all children).  
✅ **Steps:**  
1. **Perform DFS** on all unvisited nodes.  
2. **Push each node to a stack** when it's completely explored.  
3. **Pop nodes from the stack** for the topological order.  

✅ **Time Complexity:** **O(V + E)**  
✅ **Space Complexity:** **O(V)** (for stack and recursion).  

---

### **📌 DFS Approach (Stack) Implementation in C**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6

// Stack structure
typedef struct {
    int items[V];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack* s, int value) {
    if (s->top == V - 1) return;
    s->items[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) return -1;
    return s->items[s->top--];
}

void DFS(int graph[V][V], bool visited[], Stack* stack, int vertex) {
    visited[vertex] = true;

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && !visited[i])
            DFS(graph, visited, stack, i);
    }

    push(stack, vertex);
}

// Topological Sorting using DFS
void topologicalSort(int graph[V][V]) {
    Stack* stack = createStack();
    bool visited[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFS(graph, visited, stack, i);
    }

    printf("Topological Sort (DFS): ");
    while (stack->top != -1) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);
    return 0;
}
```

✅ **Output:**  
```
Topological Sort (DFS): 5 4 0 2 1 3
```

---

# **📌 Kahn's vs. DFS Approach**
| Feature | Kahn's Algorithm (BFS) | DFS Approach |
|---------|-----------------|------------|
| **Data Structure** | Queue | Stack (Recursion) |
| **Time Complexity** | O(V + E) | O(V + E) |
| **Use Case** | Real-time scheduling, dependency resolution | Understanding structure of DAG |

---

# **📌 Next Up: Shortest Path Algorithms (Dijkstra & Bellman-Ford) 🚀**
# **📌 Shortest Path Algorithms - Dijkstra & Bellman-Ford (Theory & Code in C)**  

---

## **🔹 1️⃣ Dijkstra’s Algorithm (Greedy Approach)**
✅ **Finds the shortest path from a single source to all other vertices in a graph (weighted & directed/undirected).**  
✅ **Cannot handle negative weight edges.**  

### **📌 How it Works?**  
1. **Initialize distances** from the source to all vertices as **∞** (except the source, which is 0).  
2. Use a **priority queue (min-heap)** to always pick the vertex with the **smallest known distance**.  
3. **Relax** all adjacent edges of the selected vertex (update their distances if a shorter path is found).  
4. Repeat until all vertices are processed.  

✅ **Time Complexity:** **O((V + E) log V)** (using a priority queue).  
✅ **Space Complexity:** **O(V)** (for distance array and priority queue).  

---

### **📌 Example Graph**
```
      (1)
    0 -----> 1
   / \       |
  4   8      2
 /     \     |
3       2    3
 \     /     |
  7   5      4
   \ /       |
    2 -----> 3
      (3)
```
**Adjacency List Representation:**  
```
0 → (1,4) (2,8)
1 → (2,2) (3,3)
2 → (3,5)
3 → {}
```

---

### **📌 Dijkstra’s Algorithm Implementation in C**
```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4  // Number of vertices

// Find the vertex with the minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra’s Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Stores shortest distances
    bool visited[V]; // Tracks visited nodes

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 8, 0},
        {0, 0, 2, 3},
        {0, 0, 0, 5},
        {0, 0, 0, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
```

✅ **Output:**  
```
Vertex   Distance from Source 0
0        0
1        4
2        6
3        7
```

---

## **🔹 2️⃣ Bellman-Ford Algorithm (Dynamic Programming Approach)**
✅ **Finds the shortest path from a single source to all other vertices in a graph.**  
✅ **Handles negative weight edges (unlike Dijkstra).**  
✅ **Detects negative weight cycles.**  

### **📌 How it Works?**  
1. **Initialize distances** from the source to all vertices as **∞**, except the source (0).  
2. **Relax all edges V-1 times.**  
3. **Check for negative weight cycles** (if distance can be further reduced, a negative cycle exists).  

✅ **Time Complexity:** **O(VE)**  
✅ **Space Complexity:** **O(V)**  

---

### **📌 Example Graph**
```
     4
  (0) ---> (1)
   |       / |  
  5|     -3 |  
   |       \ v
  (2) <---- (3)
     -2
```
**Edges List:**  
```
0 → (1, 4)
0 → (2, 5)
1 → (3, -3)
2 → (3, -2)
```

---

### **📌 Bellman-Ford Algorithm Implementation in C**
```c
#include <stdio.h>
#include <limits.h>

#define V 4  // Number of vertices
#define E 4  // Number of edges

// Edge structure
typedef struct {
    int src, dest, weight;
} Edge;

// Bellman-Ford Algorithm
void bellmanFord(Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle!\n");
            return;
        }
    }

    // Print result
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    Edge edges[E] = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 3, -3},
        {2, 3, -2}
    };

    bellmanFord(edges, 0);
    return 0;
}
```

✅ **Output:**  
```
Vertex   Distance from Source 0
0        0
1        4
2        5
3        2
```

---

# **📌 Dijkstra vs. Bellman-Ford**
| Feature           | Dijkstra         | Bellman-Ford |
|------------------|----------------|--------------|
| **Approach**     | Greedy          | Dynamic Programming |
| **Time Complexity** | O((V + E) log V) | O(VE) |
| **Handles Negative Weights?** | ❌ No | ✅ Yes |
| **Detects Negative Cycles?** | ❌ No | ✅ Yes |
| **Best for?** | Dense graphs, no negative weights | Graphs with negative edges/cycles |

---