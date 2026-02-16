#include "StudentGroup.h"
#include <iostream>

// Конструктор: сохраняем название группы
StudentGroup::StudentGroup(const std::string& name) {
    groupName = name;
}

// Добавляем студента в группу
void StudentGroup::addStudent(const Student& student) {
    students.push_back(student);
}

// Ищем студента по ID (неконстантная версия)
Student* StudentGroup::findStudentById(int id) {
    for (auto& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

// Ищем студента по ID (константная версия)
const Student* StudentGroup::findStudentById(int id) const {
    for (const auto& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

// Считаем средний балл по всей группе
double StudentGroup::calculateGroupAverage() const {
    if (students.empty()) {
        return 0.0;
    }

    double totalSum = 0.0;
    int totalGrades = 0;

    for (const auto& student : students) {
        const auto& studentGrades = student.getGrades();
        for (int grade : studentGrades) {
            totalSum += grade;
            totalGrades++;
        }
    }

    if (totalGrades == 0) {
        return 0.0;
    }

    return totalSum / totalGrades;
}

// Возвращаем название группы
std::string StudentGroup::getGroupName() const {
    return groupName;
}
