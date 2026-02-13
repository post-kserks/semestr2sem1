#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// Пространство имен или просто класс. В данном случае просто класс.
class Student {
public:
    // Конструктор: инициализирует id и имя студента
    Student(int id, std::string name);

    // Метод добавления оценки в список
    void addGrade(int grade);

    // Метод расчета среднего балла
    double calculateAverage() const;

    // Метод вывода информации о студенте в консоль
    void printInfo() const;

    // Геттер для ID (понадобится для поиска студента в группе)
    int getId() const;
    
    // Геттер для имени
    std::string getName() const;

private:
    int studentId; // Уникальный номер студента
    std::string name; // Имя студента
    std::vector<int> grades; // Вектор для хранения оценок
};

#endif // STUDENT_H
