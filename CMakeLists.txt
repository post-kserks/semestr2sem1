cmake_minimum_required(VERSION 3.10)

project(StudentSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(student_core
    src/Student.cpp
    src/StudentGroup.cpp
)
target_include_directories(student_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(StudentSystem main.cpp)
target_link_libraries(StudentSystem PRIVATE student_core)

include(CTest)
if(BUILD_TESTING)
    add_executable(student_system_tests
        tests/test_main.cpp
        tests/student_tests.cpp
        tests/student_group_tests.cpp
    )
    target_link_libraries(student_system_tests PRIVATE student_core)
    target_include_directories(student_system_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)

    add_test(NAME student_system_tests COMMAND student_system_tests)
endif()
