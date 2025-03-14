#include <stdio.h>

int main() {
    int a, b;
    int *pa, *pb;

    printf("Введите два целых числа: ");
    scanf("%d %d", &a, &b);

    pa = &a;
    pb = &b;

    *pa *= 2;
    *pb /= 2;

    printf("Результаты: a = %d, b = %d\n", a, b);
    return 0;
}

