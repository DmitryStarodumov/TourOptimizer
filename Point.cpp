#include "Point.hpp"
#include <cmath>

//Формула для расчёта расстояния между двумя точками на окружности (если известны их координаты): AB = √(xA−xB)2 + (yA−yB)2
double distance(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}