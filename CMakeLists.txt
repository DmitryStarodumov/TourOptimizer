cmake_minimum_required(VERSION 3.10)

# Название проекта
project(TourOptimizer)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исходных файлов
set(SOURCES
    main.cpp
    Point.cpp
    NearestNeighborOptimizer.cpp
    TwoOptOptimizer.cpp
    utils.cpp
)

# Добавление заголовочных файлов
set(HEADERS
    Point.hpp
    TourOptimizer.hpp
    NearestNeighborOptimizer.hpp
    TwoOptOptimizer.hpp
    utils.hpp
)

# Создание исполняемого файла
add_executable(TourOptimizer ${SOURCES} ${HEADERS})

# Добавление флага для использования pthread
target_link_libraries(TourOptimizer pthread)