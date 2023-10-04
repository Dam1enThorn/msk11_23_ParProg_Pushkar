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

    // Измеряем время выполнения функции saveArray
    clock_t start_time = clock();

    saveArray("my_array.bin", dynamicArray, size);

    // Измеряем время выполнения
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Время выполнения saveArray: %f секунд\n", execution_time);

    free(dynamicArray);
    
    return 0;
}
