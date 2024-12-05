#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include "Point.hpp"

const double COST_PER_UNIT = 10.0; // по условию задачи единица расстояния будет стоить 10 USD. 

std::vector<Point> generatePoints(int numPoints, double radius);
double tourCost(const std::vector<Point>& points, const std::vector<int>& tour);

#endif // UTILS_HPP