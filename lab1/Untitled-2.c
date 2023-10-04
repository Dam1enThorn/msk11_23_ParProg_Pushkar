#include <stdio.h>
#include <stdlib.h>

int* createDynamicArray(int size) {
    // Выделяем память под динамический массив
    int* array = (int*)malloc(size * sizeof(int));
    
    return array;
}
void saveArray(const char* filename, int* array, int size) {
    // Открываем файл 
    FILE* file = fopen(filename, "wb");
    
    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл для записи.\n");
        return;
    }
    
    // Записываем массив в файл
    size_t elements_written = fwrite(array, sizeof(int), size, file);
    
    // Проверяем, удалась ли запись
    if (elements_written != size) {
        printf("Ошибка при записи массива в файл.\n");
    } else {
        printf("Массив успешно записан в файл '%s'.\n", filename);
    }
    
    // Закрываем файл
    fclose(file);
}

int main() {
    int size;
    
    // Получаем размер массива от пользователя
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
    
    // Сохраняем массив в двоичный файл
    saveArray("my_array.bin", dynamicArray, size);
    
    free(dynamicArray);
    
    return 0;
}

