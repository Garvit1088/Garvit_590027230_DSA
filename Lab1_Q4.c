// Write a programe to find out factorial of a number using iterative and recursive approach.

#include <stdio.h>

long long factorial_iterative(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

long long factorial_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial using iteration: %lld\n", factorial_iterative(num));
        printf("Factorial using recursion: %lld\n", factorial_recursive(num));
    }

    return 0;
}
