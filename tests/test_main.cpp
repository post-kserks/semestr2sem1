#include "TestSuite.h"

#include <exception>
#include <iostream>
#include <vector>

namespace {

void appendTests(std::vector<TestCase>& destination, const std::vector<TestCase>& source) {
    destination.insert(destination.end(), source.begin(), source.end());
}

} // namespace

int main() {
    std::vector<TestCase> tests;
    appendTests(tests, buildStudentTests());
    appendTests(tests, buildStudentGroupTests());

    int failedCount = 0;

    for (const auto& test : tests) {
        try {
            test.run();
            std::cout << "[PASS] " << test.name << '\n';
        } catch (const std::exception& exception) {
            ++failedCount;
            std::cout << "[FAIL] " << test.name << ": " << exception.what() << '\n';
        } catch (...) {
            ++failedCount;
            std::cout << "[FAIL] " << test.name << ": unknown error\n";
        }
    }

    const int passedCount = static_cast<int>(tests.size()) - failedCount;
    std::cout << "Total: " << tests.size()
              << ", Passed: " << passedCount
              << ", Failed: " << failedCount << '\n';

    return failedCount == 0 ? 0 : 1;
}
