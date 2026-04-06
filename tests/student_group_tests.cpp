#include "Student.h"
#include "StudentGroup.h"
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

std::vector<TestCase> buildStudentGroupTests() {
    return {
        {
            "StudentGroup_ConstructorStoresGroupName",
            []() {
                StudentGroup group("BPI-231");

                ASSERT_EQ(std::string("BPI-231"), group.getGroupName());
                ASSERT_EQ(0u, group.getStudentCount());
            }
        },
        {
            "StudentGroup_AddStudentIncreasesCount",
            []() {
                StudentGroup group("BPI-231");
                Student student(1, "Alice");

                group.addStudent(student);

                ASSERT_EQ(1u, group.getStudentCount());
            }
        },
        {
            "StudentGroup_FindStudentByIdReturnsMutableStudent",
            []() {
                StudentGroup group("BPI-231");
                Student student(5, "Bob");
                group.addStudent(student);

                Student* found = group.findStudentById(5);

                ASSERT_TRUE(found != nullptr);
                found->addGrade(5);
                ASSERT_NEAR(5.0, found->calculateAverage(), 1e-9);
            }
        },
        {
            "StudentGroup_FindStudentByIdReturnsNullForMissingId",
            []() {
                StudentGroup group("BPI-231");
                Student student(2, "Chris");
                group.addStudent(student);

                Student* found = group.findStudentById(999);

                ASSERT_TRUE(found == nullptr);
            }
        },
        {
            "StudentGroup_ConstFindStudentByIdWorks",
            []() {
                StudentGroup mutableGroup("BPI-231");
                Student student(8, "Diana");
                mutableGroup.addStudent(student);
                const StudentGroup& group = mutableGroup;

                const Student* found = group.findStudentById(8);

                ASSERT_TRUE(found != nullptr);
                ASSERT_EQ(std::string("Diana"), found->getName());
            }
        },
        {
            "StudentGroup_CalculateAverageForEmptyGroupIsZero",
            []() {
                StudentGroup group("BPI-231");

                ASSERT_NEAR(0.0, group.calculateGroupAverage(), 1e-9);
            }
        },
        {
            "StudentGroup_CalculateAverageWithNoGradesIsZero",
            []() {
                StudentGroup group("BPI-231");
                group.addStudent(Student(1, "Alice"));
                group.addStudent(Student(2, "Bob"));

                ASSERT_NEAR(0.0, group.calculateGroupAverage(), 1e-9);
            }
        },
        {
            "StudentGroup_CalculateAverageUsesAllGrades",
            []() {
                StudentGroup group("BPI-231");

                Student alice(1, "Alice");
                alice.addGrade(5);
                alice.addGrade(3);

                Student bob(2, "Bob");
                bob.addGrade(4);

                group.addStudent(alice);
                group.addStudent(bob);

                ASSERT_NEAR(4.0, group.calculateGroupAverage(), 1e-9);
            }
        },
        {
            "StudentGroup_PrintAllStudentsContainsEveryName",
            []() {
                StudentGroup group("BPI-231");
                group.addStudent(Student(1, "Alice"));
                group.addStudent(Student(2, "Bob"));

                CoutCapture capture(std::cout);
                group.printAllStudents();
                const std::string output = capture.str();

                ASSERT_TRUE(output.find("Name: Alice") != std::string::npos);
                ASSERT_TRUE(output.find("Name: Bob") != std::string::npos);
            }
        }
    };
}
