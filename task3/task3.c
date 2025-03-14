#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите %d элементов массива: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, count = 0;
    printf("Отрицательные элементы: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            printf("%d (индекс %d) ", arr[i], i);
            sum += arr[i];
            count++;
        }
    }
    
    if (count > 0)
        printf("\nСреднее арифметическое отрицательных элементов: %.2f\n", (double)sum / count);
    else
        printf("\nОтрицательных элементов нет.\n");

    free(arr);
    return 0;
}
