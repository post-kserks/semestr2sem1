#include "Student.h"
#include "StudentGroup.h"
#include <iostream>

int main() {
    // Создаем группу
    StudentGroup group("CS-101");

    // Создаем студентов
    Student s1(1, "Ivan Ivanov");
    Student s2(2, "Petr Petrov");
    Student s3(3, "Sidor Sidorov");

    // Добавляем оценки студентам
    s1.addGrade(5);
    s1.addGrade(4);
    s1.addGrade(5);

    s2.addGrade(3);
    s2.addGrade(4);
    s2.addGrade(3);

    s3.addGrade(5);
    s3.addGrade(5);
    s3.addGrade(5);

    // Добавляем студентов в группу
    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);

    // Выводим информацию о группе (включая всех студентов)
    std::cout << "Initial Group Info:" << std::endl;
    group.printGroupInfo();

    // Тестируем поиск студента по ID
    std::cout << "\nUnknown Student (ID 999): " << (group.findStudentById(999) == nullptr ? "Not Found" : "Found") << std::endl;

    Student* foundStudent = group.findStudentById(2);
    if (foundStudent) {
        std::cout << "Found Student (ID 2): " << foundStudent->getName() << std::endl;
        // Добавляем еще одну оценку найденному студенту
        foundStudent->addGrade(5);
        std::cout << "Added grade 5 to " << foundStudent->getName() << std::endl;
    }

    // Выводим обновленную информацию о группе
    std::cout << "\nUpdated Group Info:" << std::endl;
    group.printGroupInfo();

    return 0;
}
