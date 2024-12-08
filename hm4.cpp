#include <stdio.h>
#include <math.h>

// Функція для обчислення таблиці значень y = e^(-dx^2)
void task1() {
    double d, x, y, h;

    // Введення кроку
    printf("Enter the step size (h > 0): ");
    scanf_s("%lf", &h);

    // Перевірка, чи крок додатній
    if (h <= 0) {
        printf("Step size must be positive.\n");
        return;
    }

    // Заголовок таблиці
    printf("d    |   x   |   y = e^(-dx^2)\n");
    printf("-------------------------------\n");

    // Перебір значень d та x в межах [-3, 3] з кроком h
    for (d = -3; d <= 3; d += h) {
        for (x = -3; x <= 3; x += h) {
            y = exp(-d * d * x * x);  // Обчислення y = e^(-dx^2)
            printf("%.2f | %.2f | %.6f\n", d, x, y);  // Виведення результату
        }
    }
}

// Функція для обчислення значення z_i
double calculate_z(double y) {
    if (fabs(y) >= 1) {
        return y;  // Якщо |y| >= 1, повертаємо y
    }
    else {
        return 0.5;  // Якщо |y| < 1, повертаємо 0.5
    }
}

// Функція для обчислення максимального значення |z_i|
void task2() {
    int n;
    double y, max_z = 0, z;

    // Введення кількості елементів
    printf("Enter the number of elements (n): ");
    scanf_s("%d", &n);

    // Перебір значень y і обчислення z_i
    for (int i = 0; i < n; i++) {
        printf("Enter y[%d]: ", i + 1);
        scanf_s("%lf", &y);

        z = calculate_z(y);  // Обчислення z_i на основі y_i
        if (fabs(z) > fabs(max_z)) {
            max_z = z;  // Оновлення max_z, якщо нове z більше за поточне max_z
        }
    }

    // Виведення результату
    printf("The maximum value of |z_i| is: %.2f\n", fabs(max_z));
}

int main() {
    // Виклик функцій для виконання задач
    task1();  // Виведення таблиці значень
    task2();  // Обчислення максимального значення |z_i|

    return 0;
}
