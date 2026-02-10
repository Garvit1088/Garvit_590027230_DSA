#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j;
    int **a, **b, **sum, **diff;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    a = (int**)malloc(r * sizeof(int*));
    b = (int**)malloc(r * sizeof(int*));
    sum = (int**)malloc(r * sizeof(int*));
    diff = (int**)malloc(r * sizeof(int*));

    for (i = 0; i < r; i++) {
        a[i] = (int*)malloc(c * sizeof(int));
        b[i] = (int*)malloc(c * sizeof(int));
        sum[i] = (int*)malloc(c * sizeof(int));
        diff[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }

    printf("Sum Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    printf("Difference Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", diff[i][j]);
        printf("\n");
    }

    for (i = 0; i < r; i++) {
        free(a[i]);
        free(b[i]);
        free(sum[i]);
        free(diff[i]);
    }

    free(a);
    free(b);
    free(sum);
    free(diff);

    return 0;
}
