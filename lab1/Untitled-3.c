#include <stdio.h>
#include <stdlib.h>

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
    // Вызываем функцию для чтения массива из двоичного файла
    readArray("my_array.bin");
    
    return 0;
}
