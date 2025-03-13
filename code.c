#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Задача №1
void task1() {
    int a, b;
    printf("Введите два целых числа a и b: ");
    scanf("%d %d", &a, &b);
    
    int *pa = &a;
    int *pb = &b;
    
    *pa *= 2;
    *pb /= 2;
    
    printf("Результат: a = %d, b = %d\n", a, b);
}

// Задача №2
void task2() {
    double *p1 = (double *)malloc(sizeof(double));
    double *p2 = (double *)malloc(sizeof(double));
    double *p3 = (double *)malloc(sizeof(double));
    
    if (!p1 || !p2 || !p3) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    
    *p1 = 12.5;
    *p2 = 24.8;
    *p3 = 37.1;
    
    printf("До обмена: p1 = %.2f, p2 = %.2f\n", *p1, *p2);
    
    double temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    printf("После обмена: p1 = %.2f, p2 = %.2f\n", *p1, *p2);
    
    free(p1);
    free(p2);
    free(p3);
}

// Задача №3
void task3() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    if (!a) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int sum = 0, count = 0;
    printf("Номера отрицательных элементов: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            printf("%d ", i);
            sum += a[i];
            count++;
        }
    }
    printf("\n");
    
    if (count > 0)
        printf("Среднее арифметическое отрицательных элементов: %.2f\n", (double)sum / count);
    else
        printf("Отрицательных элементов нет.\n");
    
    free(a);
}

// Задача №4
void task4() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    double *b = (double *)malloc(n * sizeof(double));
    double *c = (double *)malloc(n * sizeof(double));
    if (!b || !c) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    
    int c_size = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            c[c_size++] = sqrt(b[i]) / 5;
        }
    }
    
    // Сортировка выбором
    for (int i = 0; i < c_size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < c_size; j++) {
            if (c[j] < c[min_index]) {
                min_index = j;
            }
        }
        double temp = c[i];
        c[i] = c[min_index];
        c[min_index] = temp;
    }
    
    printf("Новый массив после обработки и сортировки: ");
    for (int i = 0; i < c_size; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");
    
    free(b);
    free(c);
}

int main() {
    int choice;
    do {
        printf("\nВыберите задачу (1-4) или 0 для выхода: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: printf("Выход...\n"); break;
            default: printf("Неверный ввод!\n");
        }
    } while (choice != 0);
    return 0;
}
