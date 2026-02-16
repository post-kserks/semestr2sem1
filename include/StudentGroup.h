#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include "Student.h"
#include <string>
#include <vector>

class StudentGroup {
private:
    std::string groupName;
    std::vector<Student> students;

public:
    // Конструктор
    StudentGroup(const std::string& name);

    // Методы
    void addStudent(const Student& student);
    Student* findStudentById(int id);
    double calculateGroupAverage();
    std::string getGroupName();
};

#endif
