#include <stdio.h>

struct Student {
    int roll;
    float marks;
    char grade;
};

union Data {
    int roll;
    float marks;
    char grade;
};

int main() {
    printf("Size of structure: %lu bytes\n", sizeof(struct Student));
    printf("Size of union: %lu bytes\n", sizeof(union Data));
    return 0;
}
