cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(StudentAccountingSystem)

# Указываем стандарт C++ (C++17 для удобства)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
# Включаем все .cpp файлы проекта
add_executable(lab_seminar 
    main.cpp 
    Student.cpp 
    StudentGroup.cpp
)
