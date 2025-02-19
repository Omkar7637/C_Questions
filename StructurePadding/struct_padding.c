#include <stdio.h>
#include <stddef.h>

struct Order 
{
    char ch;       // 1 byte
    double d;    // 8 bytes
    int i;    // 4 bytes
}; // Expected size: 24 bytes (due to padding)

struct OrderOptimized 
{
    double d;    // 8 bytes
    int i;    // 4 bytes
    char ch;       // 1 byte
}; // Expected size: 16 bytes (reduced padding)

int main() 
{
    printf("Size of struct Order: %zd bytes\n", sizeof(struct Order));
    printf("Size of struct OrderOptimized: %zd bytes\n", sizeof(struct OrderOptimized));

    printf("\nOffsets in struct Order:\n");
    printf("ch: %zd bytes\n", offsetof(struct Order, ch));
    printf("d: %zd bytes\n", offsetof(struct Order, d));
    printf("i: %zd bytes\n", offsetof(struct Order, i));

    printf("\nOffsets in struct OrderOptimized:\n");
    printf("d: %zd bytes\n", offsetof(struct OrderOptimized, d));
    printf("i: %zd bytes\n", offsetof(struct OrderOptimized, i));
    printf("ch: %zd bytes\n", offsetof(struct OrderOptimized, ch));

    return 0;
}
