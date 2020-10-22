#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define Pi 3.14

typedef struct {
    float R;
    float x;
    float y;

} Circle;

void Output_circle(Circle* qwerty, int i)
{
    printf("%d. Окружность: ", i);
    printf("(%f %f, %.1f)\n", qwerty->x, qwerty->y, qwerty->R);
}

void Input_circle(Circle* qwerty, int i)
{
    int err;
    printf("Введите координаты центра X и Y: \n");
    err = scanf("%f %f", &qwerty->x, &qwerty->y);
    if (err != 2) {
        printf("Введено неверно...\n");
        exit(0);
    }
    printf("Введите радиус: \n");
    err = scanf("%f", &qwerty->R);
    if ((err != 1) || (qwerty->R <= 0)) {
        printf("Введено неверно...\n");
        exit(0);
    } else {
        Output_circle(qwerty, i);
    }
}

int main()
{
    int n, err;
    printf("Введите количество кругов: \n");
    err = scanf("%d", &n);
    if (err != 1) {
        printf("Введено неверно...\n");
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        Circle c;
        Input_circle(&c, i);
    }
    return 0;
}
