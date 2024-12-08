#define _CRT_SECURE_NO_WARNINGS  // Це вимикає попередження

#include <stdio.h>
#include <math.h>

// Функція для вирішення системи рівнянь
void solve_system(double a1, double b1, double c1, double a2, double b2, double c2) {
    // Обчислюємо детермінант
    double D = a1 * b2 - a2 * b1;
    if (D != 0) {
        // Єдиний розв'язок
        double x = (-c1 * b2 + c2 * b1) / D;
        double y = (-a1 * c2 + a2 * c1) / D;
        printf("solution unis: x = %.2f, y = %.2f\n", x, y);
    }
    else {
        // D = 0, перевірка на наявність нескінченних розв'язків або їх відсутність
        if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
            printf("infinitely many solution.\n");
        }
        else {
            printf("no solutions.\n");
        }
    }
}

// Функція eReLU(x)
double eReLU(double x, double a) {
    if (x < 0) {
        return a * x; // Для x < 0
    }
    else {
        return 0; // Для x >= 0
    }
}

// Похідна функції eReLU(x)
double eReLU_derivative(double x, double a) {
    if (x < 0) {
        return a; // Похідна для x < 0
    }
    else {
        return 0; // Похідна для x >= 0
    }
}

int main() {
    // Частина 1: Рішення системи рівнянь
    double a1, b1, c1, a2, b2, c2;
    printf("koef(a1, b1, c1, a2, b2, c2):\n");
    if (scanf_s("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2) != 6) {
        printf("input failed\n");
        return 1; // Якщо зчитування не вдалося, вийдемо з програми
    }

    solve_system(a1, b1, c1, a2, b2, c2);

    // Частина 2: Функція eReLU та її похідна
    double x, a;
    printf("\n x:\n");
    if (scanf_s("%lf %lf", &x, &a) != 2) {
        printf("input failed\n");
        return 1; // Якщо зчитування не вдалося, вийдемо з програми
    }

    double result = eReLU(x, a);
    double derivative = eReLU_derivative(x, a);

    printf("eReLU(x) = %.2f\n", result);
    printf("eReLU'(x) = %.2f\n", derivative);

    return 0;
}
