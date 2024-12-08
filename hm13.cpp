#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS  // Відключаємо попередження про застарілі функції

void remove_lines_multiple_of_N(const char* filename, int N) {
    FILE* input_file;
    errno_t err = fopen_s(&input_file, filename, "r");  // Використовуємо fopen_s
    if (err != 0) {
        printf("An error occurred while opening the file for reading!\n");
        return;
    }

    // Створення тимчасового файлу для запису результатів
    FILE* temp_file;
    err = fopen_s(&temp_file, "temp.txt", "w");  // Використовуємо fopen_s
    if (err != 0) {
        printf("Error creating temporary file!\n");
        fclose(input_file);
        return;
    }

    char line[1024];
    int line_number = 1;

    // Читання файлу і запис рядків, які не кратні N
    while (fgets(line, sizeof(line), input_file)) {
        // Якщо рядок не порожній і його номер не кратний N
        if (line_number % N != 0 || strlen(line) == 1) { // line[0] == '\n' перевірка порожнього рядка
            fputs(line, temp_file);
        }
        line_number++;
    }

    fclose(input_file);
    fclose(temp_file);

    // Перейменування тимчасового файлу на оригінальний
    if (remove(filename) == 0) {
        if (rename("temp.txt", filename) != 0) {
            printf("An error occurred while renaming the file!\n");
        }
    }
    else {
        printf("Error deleting original file!\n");
    }
}

int main() {
    const char* filename = "textfile5.txt"; // Назва файлу
    int N;

    printf("Enter the number N: ");
    scanf_s("%d", &N);  // Використовуємо scanf_s

    remove_lines_multiple_of_N(filename, N);

    printf("The operation is complete.\n");

    return 0;
}
