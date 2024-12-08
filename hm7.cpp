#define _CRT_SECURE_NO_WARNINGS  // Вимикає попередження для scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція для перевірки, чи є число простим
int is_prime(int n) {
    if (n <= 1) return 0; // Числа <= 1 не прості
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0; // Якщо число ділиться на i, то воно не просте
    }
    return 1; // Число просте
}

// Функція для знаходження цифри, що зустрічається найбільше разів
int most_frequent_digit(int num) {
    int count[10] = { 0 };  // Масив для підрахунку кількості кожної цифри
    while (num != 0) {
        count[num % 10]++;  // Збільшуємо лічильник для поточної цифри
        num /= 10;  // Обрізаємо останню цифру
    }

    int max_count = 0;  // Максимальна кількість повторів
    int digit = 0;      // Цифра, що зустрічається найбільше разів

    for (int i = 9; i >= 0; i--) {  // Перевіряємо від найбільших цифр
        if (count[i] > max_count) {
            max_count = count[i];
            digit = i;
        }
    }

    return digit;
}

int main() {
    int N;

    // Введення розміру масиву
    printf("Enter the size of the array: ");
    scanf_s("%d", &N);

    // Динамічне виділення пам'яті для масиву
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Введення масиву
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &arr[i]);
    }

    // Завдання 1: Підрахунок простих чисел
    int prime_count = 0;
    for (int i = 0; i < N; i++) {
        if (is_prime(arr[i])) {
            prime_count++;
        }
    }
    printf("Number of prime numbers in the array: %d\n", prime_count);

    // Завдання 2: Найбільш часта цифра в числі
    int number;
    printf("Enter a number to find the most frequent digit: ");
    scanf_s("%d", &number);

    int result_digit = most_frequent_digit(number);
    printf("The most frequent digit is: %d\n", result_digit);

    // Звільняємо пам'ять
    free(arr);

    return 0;
}
