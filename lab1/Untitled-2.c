#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createDynamicArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    return array;
}

void saveArray(const char* filename, int* array, int size) {
    FILE* file = fopen(filename, "wb");
    
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл для записи.\n");
        return;
    }
    
    size_t elements_written = fwrite(array, sizeof(int), size, file);
    
    if (elements_written != size) {
        printf("Ошибка при записи массива в файл.\n");
    } else {
        printf("Массив успешно записан в файл '%s'.\n", filename);
    }
    
    fclose(file);
}
void findDiaposon(int *array, int size, int min, int max) {
    printf("Индексы элементов в диапазоне [%d, %d]: ", min, max);
    for (int i = 0; i < size; i++) {
        if (array[i] >= min && array[i] <= max) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    int* dynamicArray = createDynamicArray(size);
    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }
    
    printf("Вы ввели следующие элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
    
    int min, max;
        printf("Введите минимальное и максимальное значение для поиска: ");
        scanf("%d %d", &min, &max);

        // Измеряем время выполнения функции
        clock_t start_time = clock();

        findDiaposon(dynamicArray, size, min, max);
    saveArray("my_array.bin", dynamicArray, size);

    // Измеряем время выполнения
    clock_t end_time = clock();
    double execution_time2 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Время выполнения saveArray: %f секунд\n", execution_time2);
    // Сохраняем время выполнения в файл
    FILE *time_file = fopen("execution_time2.txt", "a");
    if (time_file != NULL) {
        fprintf(time_file, "Время выполнения программы: %f секунд\n", execution_time2);
        fclose(time_file);
        printf("Время выполнения сохранено в файл 'execution_time2.txt'\n");
    } else {
        printf("Не удалось открыть файл для сохранения времени выполнения.\n");
    }

    free(dynamicArray);
    
    return 0;
}
