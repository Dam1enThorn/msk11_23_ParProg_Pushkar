#include <stdio.h>

int main() {
    // Открываем файл для чтения
    FILE *file = fopen("comp_system.txt", "r");
    
    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Не удалось открыть файл 'comp_system.txt'\n");
    }
    
    // Читаем и выводим содержимое файла 
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    
    // Закрываем файл
    fclose(file);
    
    return 0;
}
