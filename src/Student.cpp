#include "Student.h"
#include <iostream>
#include <numeric> // Для std::accumulate

// Конструктор инициализирует поля класса переданными значениями
Student::Student(int id, std::string n) : studentId(id), name(n) {}

// Метод добавляет оценку в вектор оценок
void Student::addGrade(int grade) {
    grades.push_back(grade);
}

// Метод вычисляет среднее арифметическое всех оценок
double Student::calculateAverage() const {
    if (grades.empty()) {
        return 0.0; // Если оценок нет, возвращаем 0
    }
    // Суммируем все оценки
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    // Делим сумму на количество оценок
    return sum / grades.size();
}

// Метод выводит информацию о студенте
void Student::printInfo() const {
    std::cout << "ID: " << studentId << ", Name: " << name << ", Average Grade: " << calculateAverage() << std::endl;
}

// Возвращает ID студента
int Student::getId() const {
    return studentId;
}

// Возвращает имя студента
std::string Student::getName() const {
    return name;
}

// Возвращает ссылку на вектор оценок
const std::vector<int>& Student::getGrades() const {
    return grades;
}
