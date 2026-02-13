#include "Student.h"
#include <numeric> // Для std::accumulate
#include <iomanip> // Для std::setprecision

// Конструктор инициализирует поля studentId и name
Student::Student(int id, std::string n) : studentId(id), name(n) {
    // Вектор grades инициализируется пустым по умолчанию
}

// Добавляет оценку в список оценок
void Student::addGrade(int grade) {
    grades.push_back(grade);
}

// Вычисляет средний балл. Если оценок нет, возвращает 0.0.
double Student::calculateAverage() const {
    if (grades.empty()) {
        return 0.0;
    }
    // Суммируем все оценки
    int sum = std::accumulate(grades.begin(), grades.end(), 0);
    // Делим на количество оценок
    return static_cast<double>(sum) / grades.size();
}

// Выводит информацию о студенте: ID, Имя, Оценки, Средний балл
void Student::printInfo() const {
    std::cout << "ID: " << studentId << ", Name: " << name << ", Grades: [";
    for (size_t i = 0; i < grades.size(); ++i) {
        std::cout << grades[i];
        if (i < grades.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
    std::cout << ", Average: " << std::fixed << std::setprecision(2) << calculateAverage() << std::endl;
}

// Возвращает ID студента
int Student::getId() const {
    return studentId;
}

// Возвращает имя студента
std::string Student::getName() const {
    return name;
}
