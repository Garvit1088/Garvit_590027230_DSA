#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i, j;
    struct Student *s, temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = (struct Student*)malloc(n * sizeof(struct Student));
    if (s == NULL) return 1;

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].marks > s[j + 1].marks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Records (by Marks):\n");
    for (i = 0; i < n; i++)
        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);

    free(s);
    return 0;
}
