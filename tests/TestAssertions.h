#ifndef TEST_ASSERTIONS_H
#define TEST_ASSERTIONS_H

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

namespace test {

inline std::string location(const char* file, int line) {
    std::ostringstream stream;
    stream << file << ":" << line;
    return stream.str();
}

template <typename T>
inline std::string toString(const T& value) {
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

inline void assertTrue(bool condition, const char* expression, const char* file, int line) {
    if (!condition) {
        throw std::runtime_error(location(file, line) + " assertion failed: " + expression);
    }
}

template <typename Expected, typename Actual>
inline void assertEqual(
    const Expected& expected,
    const Actual& actual,
    const char* expectedExpr,
    const char* actualExpr,
    const char* file,
    int line
) {
    if (!(expected == actual)) {
        throw std::runtime_error(
            location(file, line) + " expected [" + expectedExpr + "] = " + toString(expected) +
            ", actual [" + actualExpr + "] = " + toString(actual)
        );
    }
}

inline void assertNear(
    double expected,
    double actual,
    double epsilon,
    const char* expectedExpr,
    const char* actualExpr,
    const char* file,
    int line
) {
    if (std::fabs(expected - actual) > epsilon) {
        std::ostringstream stream;
        stream << location(file, line) << " expected [" << expectedExpr << "] ~= " << expected
               << ", actual [" << actualExpr << "] = " << actual << ", eps = " << epsilon;
        throw std::runtime_error(stream.str());
    }
}

} // namespace test

#define ASSERT_TRUE(expression) \
    ::test::assertTrue((expression), #expression, __FILE__, __LINE__)

#define ASSERT_EQ(expected, actual) \
    ::test::assertEqual((expected), (actual), #expected, #actual, __FILE__, __LINE__)

#define ASSERT_NEAR(expected, actual, epsilon) \
    ::test::assertNear((expected), (actual), (epsilon), #expected, #actual, __FILE__, __LINE__)

#endif
