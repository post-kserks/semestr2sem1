#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

// Класс Student представляет студента с именем, ID и списком оценок.
class Student {
private:
    int studentId;              // Уникальный идентификатор студента
    std::string name;           // Имя студента
    std::vector<int> grades;    // Список оценок

public:
    // Конструктор: инициализирует студента с ID и именем
    Student(int id, std::string n);

    // Метод для добавления оценки (от 1 до 5, например)
    void addGrade(int grade);

    // Метод для расчета среднего балла студента
    double calculateAverage() const;

    // Метод для вывода информации о студенте в консоль
    void printInfo() const;

    // Геттер для получения ID студента (понадобится для поиска)
    int getId() const;
    
    // Геттер для получения имени (для вывода)
    std::string getName() const;
};

#endif // STUDENT_H
