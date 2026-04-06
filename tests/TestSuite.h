#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <functional>
#include <string>
#include <vector>

struct TestCase {
    std::string name;
    std::function<void()> run;
};

std::vector<TestCase> buildStudentTests();
std::vector<TestCase> buildStudentGroupTests();

#endif
