#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i, maxIndex = 0;
    struct Employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    emp = (struct Employee*)malloc(n * sizeof(struct Employee));
    if (emp == NULL) return 1;

    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    for (i = 1; i < n; i++) {
        if (emp[i].salary > emp[maxIndex].salary)
            maxIndex = i;
    }

    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\nName: %s\nSalary: %.2f\n",
           emp[maxIndex].id, emp[maxIndex].name, emp[maxIndex].salary);

    free(emp);
    return 0;
}
