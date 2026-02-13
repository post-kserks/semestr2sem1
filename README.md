# Система учета студентов

## Описание
Программа позволяет создавать студентов, добавлять их в группы, выставлять оценки и рассчитывать средний балл студентов и групп.

## Структура проекта
- `CMakeLists.txt`: Конфигурация сборки через CMake.
- `Student.h`/`Student.cpp`: Класс `Student`.
- `StudentGroup.h`/`StudentGroup.cpp`: Класс `StudentGroup`.
- `main.cpp`: Пример использования классов.

## Сборка и запуск

### Используя CMake (рекомендуется)
1. Создайте директорию сборки:
   ```bash
   mkdir build && cd build
   ```
2. Сгенерируйте файлы сборки:
   ```bash
   cmake ..
   ```
3. Скомпилируйте проект:
   ```bash
   make
   ```
4. Запустите программу:
   ```bash
   ./lab_seminar
   ```

### Используя g++ напрямую (если CMake не установлен)
```bash
g++ -std=c++17 main.cpp Student.cpp StudentGroup.cpp -o lab_seminar
./lab_seminar
```
