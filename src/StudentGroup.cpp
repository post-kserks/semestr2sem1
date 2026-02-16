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

// Ищем студента по ID
Student* StudentGroup::findStudentById(int id) {
    // Проходим по всем студентам
    for (int i = 0; i < students.size(); i++) {
        // Используем твой метод getId()
        if (students[i].getId() == id) {
            return &students[i];  // Возвращаем указатель на найденного студента
        }
    }
    return nullptr;  // Не нашли
}

// Считаем средний балл по всей группе
double StudentGroup::calculateGroupAverage() {
    // Если в группе нет студентов
    if (students.size() == 0) {
        return 0.0;
    }

    double totalSum = 0.0;
    int totalGrades = 0;

    // Проходим по всем студентам
    for (int i = 0; i < students.size(); i++) {
        // Получаем оценки текущего студента
        // У тебя в Student.h должен быть геттер getGrades()
        std::vector<int> studentGrades = students[i].getGrades();

        // Суммируем оценки
        for (int j = 0; j < studentGrades.size(); j++) {
            totalSum += studentGrades[j];
            totalGrades++;
        }
    }

    // Если нет ни одной оценки
    if (totalGrades == 0) {
        return 0.0;
    }

    return totalSum / totalGrades;
}

// Возвращаем название группы
std::string StudentGroup::getGroupName() {
    return groupName;
}
