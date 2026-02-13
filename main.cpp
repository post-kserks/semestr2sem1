#include <iostream>
#include "Student.h"

int main() {
    // Создаем объект студента с ID 1 и именем "Ivan Ivanov"
    Student student1(1, "Ivan Ivanov");

    // Добавляем оценки
    student1.addGrade(5);
    student1.addGrade(4);
    student1.addGrade(5);

    // Выводим информацию
    std::cout << "Testing Student class:" << std::endl;
    student1.printInfo();

    std::cout << "Grades: ";
    for (int grade : student1.getGrades()) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    // Проверяем расчет среднего балла
    // (5 + 4 + 5) / 3 = 14 / 3 = 4.666...
    std::cout << "Calculated Average: " << student1.calculateAverage() << std::endl;

    return 0;
}
