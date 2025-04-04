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
        "movl %%eax, (%[py])\n\t"
        : // no output operands
        : [px] "r" (x), [py] "r" (y) // input operands: addresses of x and y
        : "eax", "ebx" // clobbered registers
    );
}


//main function
int main() {
    // variable declarations
    int a, b;

    // test case 1: standard c swap -----
    a = 20;
    b = 23;
    printf("-- Before Standard --\n");
    printf("a: %d\nb: %d\n", a, b);
    swap(&a, &b);
    printf("-- After Standard --\n");
    printf("a: %d\nb: %d\n", a, b);

    // test case 2: assembly swap -----
    a = 18;
    b = 61;
    printf("-- Before Assembly --");
    printf("a: %d\nb: %d", a, b);
    swap_asm(&a, &b);
    printf("-- After Assembly --");
    printf("a: %d\nb: %d", a, b);
    return 0;
}