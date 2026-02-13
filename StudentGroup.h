#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include "Student.h"
#include <string>
#include <vector>

// Класс StudentGroup представляет группу студентов.
class StudentGroup {
private:
    std::string groupName;              // Название группы
    std::vector<Student> students;      // Список студентов в группе

public:
    // Конструктор: инициализирует группу названием
    explicit StudentGroup(std::string name);

    // Добавляет студента в группу
    void addStudent(const Student& s);

    // Ищет студента по ID. Возвращает указатель на студента или nullptr, если не найден.
    Student* findStudentById(int id);

    // Вычисляет средний балл по всей группе
    double calculateGroupAverage() const;

    // Выводит информацию о всех студентах в группе
    void printGroupInfo() const;
};

#endif // STUDENTGROUP_H
