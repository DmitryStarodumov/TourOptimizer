Задача:
Случайным образом задаются сто точек точки внутри окружности. 
Соединить их таким образом, чтобы каждая точка была соединена как минимум с двумя соседними, как максимум - с шестью.

Теперь представим, что мы путешествуем из первой точки в какую-то (задаётся пользователем). 
Но мы хотим посетить все точки и потратить как можно меньше денег. 
Скажем, единица расстояния будет стоить 10 USD. 
Найти путь, который будет стоить минимум (или близкое к нему количество) денег.

Задача похожа на решение Задачи коммивояжёра(https://ru.wikipedia.org/wiki/Задача_коммивояжёра), поэтому часть кода по оптимизации маршрута будет иметь готовые алгоритмы (например 2-opt)

Структура проекта:
TourOptimizer/
├── CMakeLists.txt
├── main.cpp
├── Point.hpp
├── Point.cpp
├── TourOptimizer.hpp
├── NearestNeighborOptimizer.hpp
├── NearestNeighborOptimizer.cpp
├── TwoOptOptimizer.hpp
├── TwoOptOptimizer.cpp
├── utils.hpp
└── utils.cpp

Сборка проекта:
Создайте директорию для сборки:
mkdir build
cd build

Запустите CMake для генерации Makefile:
cmake ..

Соберите проект:
make

Запустите исполняемый файл:
./TourOptimizer