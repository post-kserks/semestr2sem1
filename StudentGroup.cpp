#include "StudentGroup.h"
#include <iostream>
#include <numeric>

// Конструктор инициализирует группу заданным именем
StudentGroup::StudentGroup(std::string name) : groupName(name) {
    // Вектор students инициализируется пустым
}

// Добавляет студента в конец вектора
void StudentGroup::addStudent(const Student& s) {
    students.push_back(s);
}

// Поиск студента по ID
Student* StudentGroup::findStudentById(int id) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return &students[i]; // Возвращаем адрес найденного студента
        }
    }
    return nullptr; // Если не нашли
}

// Вычисляет общий средний балл группы
double StudentGroup::calculateGroupAverage() const {
    if (students.empty()) {
        return 0.0;
    }

    double totalSum = 0.0;
    for (const auto& student : students) {
        totalSum += student.calculateAverage();
    }
    return totalSum / students.size();
}

// Выводит информацию о группе и каждом студенте
void StudentGroup::printGroupInfo() const {
    std::cout << "--- Group: " << groupName << " ---" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
    }
    std::cout << "Group Average: " << calculateGroupAverage() << std::endl;
    std::cout << "----------------------" << std::endl;
}
