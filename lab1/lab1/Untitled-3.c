#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readArray(const char* filename) {
    // Открываем файл для чтения в двоичном режиме
    FILE* file = fopen(filename, "rb");
    
    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл для чтения.\n");
        return;
    }
    
    // Определяем размер файла, чтобы знать, сколько элементов в массиве
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Рассчитываем количество элементов в массиве
    int array_size = file_size / sizeof(int);
    
    // Создаем массив для считанных данных
    int* array = (int*)malloc(array_size * sizeof(int));
    
    // Считываем данные из файла в массив
    size_t elements_read = fread(array, sizeof(int), array_size, file);
    
    // Проверяем, удалось ли считать данные
    if (elements_read != array_size) {
        printf("Ошибка при чтении массива из файла.\n");
    } else {
        printf("Содержимое массива из файла '%s':\n", filename);
        for (int i = 0; i < array_size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    
    // Закрываем файл и освобождаем память
    fclose(file);
    free(array);
}

int main() {
    // Измеряем время выполнения программы
    clock_t start_time = clock();
    // Вызываем функцию для чтения массива из двоичного файла
    readArray("my_array.bin");
     // Измеряем время выполнения программы
    clock_t end_time = clock();
   // Вычисляем время выполнения в секундах
    double execution_time3 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Время выполнения программы: %f секунд\n", execution_time3);
    // Сохраняем время выполнения в файл
    FILE *time_file = fopen("execution_time3.txt", "a");
    if (time_file != NULL) {
        fprintf(time_file, "Время выполнения программы: %f секунд\n", execution_time3);
        fclose(time_file);
        printf("Время выполнения сохранено в файл 'execution_time3.txt'\n");
    } else {
        printf("Не удалось открыть файл для сохранения времени выполнения.\n");
    }
    return 0;
}
