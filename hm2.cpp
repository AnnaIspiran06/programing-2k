#define _CRT_SECURE_NO_WARNINGS  // Вимикаємо попередження про небезпеку scanf
#include <stdio.h>
#include <math.h>

// Визначення константи для M_PI, якщо її немає в стандарті компілятора
#define M_PI 3.14159265358979323846

// Функція для обчислення об'єму циліндра
double cylinder_volume(double r, double h) {
    return M_PI * r * r * h;  // M_PI - константа для значення числа π
}

// Функція для f(x) = arctg(x)
double arctg(double x) {
    return atan(x);  // Функція для обчислення арктангенса
}

// Похідна функції f(x) = arctg(x), g(x) = 1 / (1 + x^2)
double arctg_derivative(double x) {
    return 1 / (1 + x * x);  // Похідна функції arctg(x)
}

int main() {
    // Частина 1: Обчислення об'єму циліндра
    double radius, height;
    printf("r: ");
    if (scanf_s("%lf", &radius) != 1) {  // Перевірка коректності вводу
        printf("Невірний ввід для радіусу\n");
        return 1;
    }
    printf("h: ");
    if (scanf_s("%lf", &height) != 1) {  // Перевірка коректності вводу
        printf("Невірний ввід для висоти\n");
        return 1;
    }

    double volume = cylinder_volume(radius, height);
    printf("V: %.2f\n", volume);

    // Частина 2: Обчислення арктангенса та його похідної
    double x;
    printf("x: ");
    if (scanf_s("%lf", &x) != 1) {  // Перевірка коректності вводу
        printf("Невірний ввід для x\n");
        return 1;
    }

    double arctg_value = arctg(x);
    double arctg_derivative_value = arctg_derivative(x);

    printf("f(x) = arctg(x): %.2f\n", arctg_value);
    printf("f'(x) = 1 / (1 + x^2): %.2f\n", arctg_derivative_value);

    return 0;
}
