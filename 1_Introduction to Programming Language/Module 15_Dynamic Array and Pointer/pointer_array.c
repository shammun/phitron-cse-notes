#include <stdio.h>

int main(){
    // Declare an integer array with 5 elements and initialize it
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Create a pointer p that points to the first element of array
    // Note: Array name itself acts as pointer to its first element
    int *p = arr;  // Same as int *p = &arr[0]

    // Print addresses to show that array name and pointer p contain same address
    // %p format specifier is used to print addresses in hexadecimal format
    printf("Address of the first element of the array: %p and the value of p is: %p \n", arr, p);
    // Address of the first element of the array: 0x7ffeb0e5ff60 and the value of p is: 0x7ffeb0e5ff60


    // Print address of next element (p+1)
    // Since p is integer pointer, p+1 will add sizeof(int) bytes to current address
    // If p points to address 1000 and sizeof(int) is 4, p+1 will point to 1004
    printf("Address of the next element of the array: %p\n", p+1);
    // Address of the next element of the array: 0x7ffeb0e5ff64


    // Declare integer variable and pointer to demonstrate pointer arithmetic
    int a = 6;
    int *x = &a;

    // Print current address (x) and next address (x+1)
    // Notice the difference between addresses is sizeof(int) bytes (typically 4)
    printf("The value of x and x+1 are: %p and %p\n", x, x+1);
    // The value of x and x+1 are: 0x7ffeb0e5ff44 and 0x7ffeb0e5ff48


    // Demonstrate pointer arithmetic with different data type (char)
    char ch = 'a';
    char *y = &ch;

    // Print current address (y) and next address (y+1)
    // Since char size is 1 byte, difference between y and y+1 is only 1 byte
    // This shows pointer arithmetic depends on data type of pointer
    printf("The value of y and y+1 are: %p and %p\n", y, y+1);
    // The value of y and y+1 are: 0x7ffeb0e5ff43 and 0x7ffeb0e5ff44

    
    return 0;
}