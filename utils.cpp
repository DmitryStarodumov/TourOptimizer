#include "utils.hpp"
#include <random>
#include <cmath>

std::vector<Point> generatePoints(int numPoints, double radius) {
    std::vector<Point> points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < numPoints; ++i) {
        double angle = dis(gen) * 2 * M_PI;
        double r = radius * std::sqrt(dis(gen));
        points.push_back({r * std::cos(angle), r * std::sin(angle)});
    }

    return points;
}

double tourCost(const std::vector<Point>& points, const std::vector<int>& tour) {
    double cost = 0.0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        cost += distance(points[tour[i]], points[tour[i + 1]]);
    }
    cost += distance(points[tour.back()], points[tour[0]]);
    return cost * COST_PER_UNIT;
}