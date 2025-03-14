#include <stdio.h>
#include <stdlib.h>

int main() {
    double *p1, *p2, *p3;
    
    p1 = (double *)malloc(sizeof(double));
    p2 = (double *)malloc(sizeof(double));
    p3 = (double *)malloc(sizeof(double));

    if (!p1 || !p2 || !p3) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    *p1 = 3.14;
    *p2 = 2.71;
    *p3 = 1.41;

    double temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("p1 = %.2f, p2 = %.2f, p3 = %.2f\n", *p1, *p2, *p3);

    free(p1);
    free(p2);
    free(p3);
    
    return 0;
}

