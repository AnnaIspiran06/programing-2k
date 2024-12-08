#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_and_write_exponent(const char* filename) {
    FILE* file = NULL;
    // Використовуємо fopen_s для безпеки
    if (fopen_s(&file, filename, "r+")) {
        printf("Помилка при відкритті файлу!\n");
        return;
    }

    int* numbers = NULL;
    int count = 0;

    // Спочатку читаємо числа з файлу, щоб дізнатися кількість елементів
    while (!feof(file)) {
        int temp;
        if (fscanf_s(file, "%d", &temp) == 1) {
            count++;
            int* tempNumbers = (int*)realloc(numbers, count * sizeof(int));

            // Перевірка на успішність realloc
            if (tempNumbers == NULL) {
                printf("Помилка при виділенні пам'яті!\n");
                free(numbers);  // Звільняємо пам'ять перед виходом
                fclose(file);
                return;
            }

            numbers = tempNumbers;  // Якщо realloc успішно повернув новий вказівник
            numbers[count - 1] = temp;
        }
    }

    // Повертаємось на початок файлу для запису результатів
    fseek(file, 0, SEEK_SET);

    // Обчислюємо експоненти і записуємо в файл
    for (int i = 0; i < count; i++) {
        double exp_val = exp(numbers[i]);  // Обчислюємо експоненту для числа
        // Використовуємо безпечну версію функції fprintf_s
        fprintf_s(file, "%d %.6f\n", numbers[i], exp_val);
    }

    // Очищаємо пам'ять
    free(numbers);

    // Закриваємо файл
    fclose(file);
}

int main() {
    const char* filename = "TextFile2.txt";  // Вказуємо назву файлу

    calculate_and_write_exponent(filename);

    return 0;
}
