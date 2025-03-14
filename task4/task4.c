#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void selection_sort(double *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        double temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int *b = (int *)malloc(n * sizeof(int));
    if (!b) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите %d элементов массива: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    double *c = (double *)malloc(n * sizeof(double));
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            c[count++] = sqrt(b[i]) / 5.0;
        }
    }

    selection_sort(c, count);

    printf("Отсортированный массив: ");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");

    free(b);
    free(c);
    return 0;
}
