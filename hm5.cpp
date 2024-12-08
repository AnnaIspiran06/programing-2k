#define _CRT_SECURE_NO_WARNINGS  // Вимикає попередження щодо небезпечних функцій, таких як scanf

#include <stdio.h>
#include <math.h>

// Функція для обчислення факторіалу
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Функція для обчислення v_i за заданим рекурентним співвідношенням
double calculate_v(int i) {
    double v[3] = { 1, 1, 1 };  // v0 = v1 = v2 = 1

    if (i <= 2) {
        return v[i];
    }

    for (int j = 3; j <= i; j++) {
        v[j % 3] = (j + 4) * (v[(j - 1) % 3] + (j + 5) * v[(j - 3) % 3]);
    }

    return v[i % 3];
}

// Функція для обчислення наближеної суми для ln(1 + x)
double ln_approximation(double x, double epsilon) {
    double sum = 0.0;
    double term = x;
    int n = 1;

    // Обчислюємо суму до тих пір, поки доданок не буде меншим за epsilon
    while (fabs(term) >= epsilon) {
        sum += term;
        n++;
        term = ((n % 2 == 0) ? -1 : 1) * pow(x, n) / factorial(n);
    }

    return sum;
}

int main() {
    // Завдання 1: Обчислення елементів послідовності v_i
    int index;
    printf("Enter the index of the sequence element (v_i): ");
    scanf("%d", &index);  // Використовуємо scanf замість scanf_s для більш універсальності
    double v_value = calculate_v(index);
    printf("The value of v[%d] is: %.2f\n", index, v_value);

    // Завдання 2: Обчислення наближеної суми для ln(1 + x)
    double x, epsilon;
    printf("Enter the value of x for ln(1 + x): ");
    scanf("%lf", &x);  // Використовуємо scanf для зручності
    printf("Enter the epsilon for the approximation: ");
    scanf("%lf", &epsilon);  // Використовуємо scanf для зручності

    double ln_value = ln_approximation(x, epsilon);
    printf("The approximation of ln(1 + %.2f) is: %.6f\n", x, ln_value);

    return 0;
}
