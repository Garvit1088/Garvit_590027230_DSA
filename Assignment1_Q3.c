#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Largest element = %d\n", max);
    printf("Smallest element = %d\n", min);

    free(arr);
    return 0;
}
