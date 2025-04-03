/*
This program utilizes a function called swap(a,b)
to swap two variables, coded in assembly language.
*/

// include statements
#include <stdio.h>

// swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// swap function in assembly
void swap_asm(int *x, int *y) {
    __asm__ volatile (
        "movl (%[px]), %%eax\n\t"
        "movl (%[py]), %%ebx\n\t"
        "movl %%ebx, (%[px])\n\t"
        "movl %%eas, (%[py])\n\t"
        : // no output operands
        : [px] "r" (x), [py] "r" (y) // input operands: addresses of x and y
        : "eax", "ebx" // clobbered registers
    );
}


//main function
int main() {
    // code here
    return 0;
}