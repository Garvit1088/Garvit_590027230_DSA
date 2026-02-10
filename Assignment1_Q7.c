#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *s = NULL;
    int choice, n = 0, i, roll, found, newSize;

    while (1) {
        printf("\n1. Add Record\n2. Display Records\n3. Delete Record\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            newSize = n + 1;
            s = realloc(s, newSize * sizeof(struct Student));
            printf("Enter Roll, Name, Marks: ");
            scanf("%d", &s[n].roll);
            scanf(" %[^\n]", s[n].name);
            scanf("%f", &s[n].marks);
            n++;
        }
        else if (choice == 2) {
            if (n == 0) printf("No records\n");
            for (i = 0; i < n; i++)
                printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
        }
        else if (choice == 3) {
            printf("Enter roll to delete: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    found = 1;
                    for (int j = i; j < n - 1; j++)
                        s[j] = s[j + 1];
                    n--;
                    s = realloc(s, n * sizeof(struct Student));
                    break;
                }
            }
            if (!found) printf("Record not found\n");
        }
        else if (choice == 4) {
            free(s);
            printf("Memory freed. Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
