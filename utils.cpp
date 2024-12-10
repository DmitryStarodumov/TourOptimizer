#include "utils.hpp"
#include <random>
#include <cmath>

std::vector<Point> generatePoints(int numPoints, double radius) {
    std::vector<Point> points(numPoints);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < numPoints; ++i) {
        double angle = dis(gen) * 2 * M_PI;
        points[i] = {radius * cos(angle), radius * sin(angle)}; // Points on the circle
    }

    return points;
}