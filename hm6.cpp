#define _CRT_SECURE_NO_WARNINGS  // Це вимикає попередження про використання небезпечних функцій

#include <stdio.h>

// Функція для обнулення лівих k біт
unsigned int set_left_k_bits_to_zero(unsigned int m, int k) {
    unsigned int mask = ~((1 << k) - 1);  // Створюємо маску, яка обнуляє ліві k біт
    return m & mask;  // Використовуємо побітове І для обнулення лівих біт
}

// Функція для обнулення правих k біт
unsigned int set_right_k_bits_to_zero(unsigned int m, int k) {
    unsigned int mask = ~((1 << k) - 1);  // Створюємо маску, яка обнуляє праві k біт
    return m & mask;  // Використовуємо побітове І для обнулення правих біт
}

// Функція для перевірки, чи два числа не мають нульових біт на однакових позиціях
int check_no_common_zero_bits(unsigned int m1, unsigned int m2) {
    return (m1 & m2) == 0;  // Перевіряємо, чи немає спільних нульових бітів
}

int main() {
    unsigned int m1, m2;
    int k;

    // Введення для першого числа m1
    printf("Enter a natural number (m1) and number of bits (k): ");
    if (scanf_s("%u %d", &m1, &k) != 2) {  // Використовуємо scanf_s для безпеки
        printf("Invalid input.\n");
        return 1;
    }

    // Виведення результатів для m1
    unsigned int result_left_m1 = set_left_k_bits_to_zero(m1, k);
    unsigned int result_right_m1 = set_right_k_bits_to_zero(m1, k);
    printf("After setting left %d bits to zero (m1): %u (Decimal), %o (Octal)\n", k, result_left_m1, result_left_m1);
    printf("After setting right %d bits to zero (m1): %u (Decimal), %o (Octal)\n", k, result_right_m1, result_right_m1);

    // Введення для другого числа m2
    printf("Enter another number (m2) and number of bits (k): ");
    if (scanf_s("%u %d", &m2, &k) != 2) {  // Використовуємо scanf_s для безпеки
        printf("Invalid input.\n");
        return 1;
    }

    // Виведення результатів для m2
    unsigned int result_left_m2 = set_left_k_bits_to_zero(m2, k);
    unsigned int result_right_m2 = set_right_k_bits_to_zero(m2, k);
    printf("After setting left %d bits to zero (m2): %u (Decimal), %o (Octal)\n", k, result_left_m2, result_left_m2);
    printf("After setting right %d bits to zero (m2): %u (Decimal), %o (Octal)\n", k, result_right_m2, result_right_m2);

    // Перевірка на наявність спільних нульових бітів
    if (check_no_common_zero_bits(m1, m2)) {
        printf("m1 and m2 do not have zero bits at the same positions.\n");
    }
    else {
        printf("m1 and m2 have zero bits at the same positions.\n");
    }

    return 0;
}
