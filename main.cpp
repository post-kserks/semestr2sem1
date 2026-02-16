#include <iostream>
#include <iomanip>
#include "Student.h"
#include "StudentGroup.h"

int main() {
    // Устанавливаем вывод чисел с плавающей точкой до 2 знаков после запятой
    std::cout << std::fixed << std::setprecision(2);

    // --- Тестирование класса Student ---
    std::cout << "=== Testing Student class ===" << std::endl;
    Student s1(1, "Ivan Ivanov");
    s1.addGrade(5);
    s1.addGrade(4);
    s1.addGrade(5);
    s1.printInfo();

    Student s2(2, "Maria Petrova");
    s2.addGrade(5);
    s2.addGrade(5);
    s2.addGrade(3);
    s2.printInfo();

    std::cout << std::endl;

    // --- Тестирование класса StudentGroup ---
    std::cout << "=== Testing StudentGroup class ===" << std::endl;
    StudentGroup group("BPI-231");
    std::cout << "Group: " << group.getGroupName() << std::endl;

    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(Student(3, "Alexey Sidorov"));

    // Поиск и добавление оценки через группу
    std::cout << "Searching for student with ID 3..." << std::endl;
    Student* found = group.findStudentById(3);
    if (found) {
        std::cout << "Found: " << found->getName() << ". Adding grade 4." << std::endl;
        found->addGrade(4);
    } else {
        std::cout << "Student with ID 3 not found!" << std::endl;
    }

    // Расчет среднего балла группы
    double groupAvg = group.calculateGroupAverage();
    std::cout << "Group average grade: " << groupAvg << std::endl;

    // Проверка поиска несуществующего студента
    if (group.findStudentById(99) == nullptr) {
        std::cout << "Student with ID 99 correctly not found." << std::endl;
    }

    return 0;
}
