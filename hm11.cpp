#include <stdio.h>
#include <stdlib.h>

void check_and_rearrange_numbers(const char* input_file, const char* output_file) {
    FILE* input_fp = NULL;
    FILE* output_fp = NULL;

    // Використовуємо fopen_s для більшої безпеки
    if (fopen_s(&input_fp, input_file, "r") != 0 || fopen_s(&output_fp, output_file, "w") != 0) {
        printf("Error!\n");
        return;
    }

    int numbers[1000];
    int positive_count = 0, negative_count = 0;
    int i = 0;

    // Читання чисел з файлу
    while (fscanf_s(input_fp, "%d", &numbers[i]) == 1) {
        if (numbers[i] > 0) {
            positive_count++;
        }
        else if (numbers[i] < 0) {
            negative_count++;
        }
        i++;
    }

    // Перевірка на рівність кількості додатних і відʼємних чисел
    if (positive_count != negative_count) {
        printf("the number of positive and negative numbers is not equal.\n");
        fclose(input_fp);
        fclose(output_fp);
        return;
    }

    // Переписуємо числа: спочатку додатні, потім відʼємні
    for (int j = 0; j < i; j++) {
        if (numbers[j] > 0) {
            fprintf(output_fp, "%d ", numbers[j]);
        }
    }
    for (int j = 0; j < i; j++) {
        if (numbers[j] < 0) {
            fprintf(output_fp, "%d ", numbers[j]);
        }
    }

    printf("the numbers are copied to file '%s'  in the appropriate order.\n", output_file);

    fclose(input_fp);
    fclose(output_fp);
}

int main() {
    // Використовуємо const char* для шляху до файлів
    const char* input_file = "TextFile3.txt"; // F
    const char* output_file = "TextFile4.txt"; // G

    check_and_rearrange_numbers(input_file, output_file);

    return 0;
}
