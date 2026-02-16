#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "StudentGroup.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "     СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ v1.0\n";
    std::cout << "========================================\n\n";

    std::cout << std::fixed << std::setprecision(2);

    StudentGroup group("БПИ-231");

    Student s1(1, "Иван Иванов");
    Student s2(2, "Мария Петрова");
    Student s3(3, "Алексей Сидоров");
    Student s4(4, "Елена Козлова");

    // Имитация добавления оценок перед зачислением
    s1.addGrade(5); s1.addGrade(4);
    s2.addGrade(5); s2.addGrade(5);
    s4.addGrade(3); s4.addGrade(4);

    std::cout << "🎓 Формирование группы " << group.getGroupName() << "...\n";
    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);
    group.addStudent(s4);

    std::cout << "✅ Зачислено студентов: " << group.getStudentCount() << "\n\n";

    std::cout << "📝 Список всех студентов:\n";
    std::cout << "--------------------\n";
    group.printAllStudents();
    std::cout << "--------------------\n\n";

    std::cout << "🔍 Поиск студента по ID (3)...\n";
    Student* foundStudent = group.findStudentById(3);

    if (foundStudent) {
        std::cout << "✅ Найден: " << foundStudent->getName() << "\n";
        std::cout << "📊 Текущий средний балл: " << foundStudent->calculateAverage() << "\n";
        
        std::cout << "✍️ Добавление новой оценки (5)...\n";
        foundStudent->addGrade(5);
        
        std::cout << "📈 Обновленный средний балл: " << foundStudent->calculateAverage() << "\n\n";
    }

    std::cout << "🏆 Общая статистика группы:\n";
    std::cout << "---------------------------\n";
    std::cout << "Средний балл всей группы: " << group.calculateGroupAverage() << "\n";
    std::cout << "Количество отличников: " << (group.calculateGroupAverage() > 4.5 ? "высокое" : "среднее") << "\n\n";

    std::cout << "========================================\n";
    std::cout << "     ТЕСТИРОВАНИЕ ЗАВЕРШЕНО\n";
    std::cout << "========================================\n";

    return 0;
}
