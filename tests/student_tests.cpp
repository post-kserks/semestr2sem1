#include "Student.h"
#include "TestAssertions.h"
#include "TestSuite.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {

class CoutCapture {
public:
    explicit CoutCapture(std::ostream& stream)
        : captured(), stream(stream), oldBuffer(stream.rdbuf(captured.rdbuf())) {}

    ~CoutCapture() {
        stream.rdbuf(oldBuffer);
    }

    std::string str() const {
        return captured.str();
    }

private:
    std::ostringstream captured;
    std::ostream& stream;
    std::streambuf* oldBuffer;
};

} // namespace

std::vector<TestCase> buildStudentTests() {
    return {
        {
            "Student_ConstructorStoresIdAndName",
            []() {
                Student student(7, "Alice");

                ASSERT_EQ(7, student.getId());
                ASSERT_EQ(std::string("Alice"), student.getName());
            }
        },
        {
            "Student_EmptyGradesAverageIsZero",
            []() {
                Student student(1, "Bob");

                ASSERT_NEAR(0.0, student.calculateAverage(), 1e-9);
            }
        },
        {
            "Student_AddGradeUpdatesAverage",
            []() {
                Student student(2, "Chris");
                student.addGrade(5);
                student.addGrade(3);
                student.addGrade(4);

                ASSERT_NEAR(4.0, student.calculateAverage(), 1e-9);
            }
        },
        {
            "Student_GetGradesReturnsStoredValues",
            []() {
                Student student(3, "Diana");
                student.addGrade(2);
                student.addGrade(5);

                const auto& grades = student.getGrades();
                ASSERT_EQ(2u, grades.size());
                ASSERT_EQ(2, grades[0]);
                ASSERT_EQ(5, grades[1]);
            }
        },
        {
            "Student_PrintInfoContainsIdentityAndAverage",
            []() {
                Student student(11, "Eva");
                student.addGrade(4);
                student.addGrade(5);

                CoutCapture capture(std::cout);
                student.printInfo();
                const std::string output = capture.str();

                ASSERT_TRUE(output.find("ID: 11") != std::string::npos);
                ASSERT_TRUE(output.find("Name: Eva") != std::string::npos);
                ASSERT_TRUE(output.find("Average Grade: 4.5") != std::string::npos);
            }
        }
    };
}
