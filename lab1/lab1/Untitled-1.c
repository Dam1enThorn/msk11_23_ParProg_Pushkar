#include <stdio.h>
#include <time.h>

void readAndPrintFile(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Не удалось открыть файл '%s'\n", filename);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    // Измеряем время выполнения программы
    clock_t start_time = clock();

    readAndPrintFile("comp_system.txt");

    // Измеряем время выполнения программы
    clock_t end_time = clock();

    // Вычисляем время выполнения в секундах
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Время выполнения программы: %f секунд\n", execution_time);

    // Сохраняем время выполнения в файл
    FILE *time_file = fopen("execution_time1.txt", "a");
    if (time_file != NULL) {
        fprintf(time_file, "Время выполнения программы: %f секунд\n", execution_time);
        fclose(time_file);
        printf("Время выполнения сохранено в файл 'execution_time.txt'\n");
    } else {
        printf("Не удалось открыть файл для сохранения времени выполнения.\n");
    }

    return 0;
}
