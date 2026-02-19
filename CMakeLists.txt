cmake_minimum_required(VERSION 3.10) 

# Имя проекта
project(StudentSystem) 

# Указываем стандарт C++ (C++17) 
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 

# Добавляем директорию с заголовочными файлами в путь поиска
include_directories(include) 

# Собираем список всех исходных файлов в директории src
file(GLOB SOURCES "src/*.cpp") 

# Создаем исполняемый файл из main.cpp и найденных исходников
# Обратите внимание: main.cpp должен быть в корне или добавлен сюда, если он есть
add_executable(StudentSystem main.cpp ${SOURCES}) 
