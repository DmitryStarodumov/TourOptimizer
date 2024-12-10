#include <iostream>
#include <vector>
#include <algorithm> // Для std::find и std::rotate
#include "Point.hpp"
#include "FinalTourOptimizer.hpp"
#include "utils.hpp"

const int NUM_POINTS = 100; //общее количество точек
const double RADIUS = 10.0; //радиус окружности по условию не определен, поэтому используем 10 по дефолту

int main() {
    std::vector<Point> points = generatePoints(NUM_POINTS, RADIUS);

    int start_point = 0;
    int destination_point;
    std::cout << "Enter the final destination point index (1 to " << NUM_POINTS - 1 << "): ";
    std::cin >> destination_point;

    if (destination_point < 1 || destination_point >= NUM_POINTS) {
        std::cerr << "Invalid destination point index." << std::endl;
        return 1;
    }

    FinalTourOptimizer optimizer(points);
    std::vector<int> tour = optimizer.optimize(start_point, destination_point);

    double total_cost = optimizer.getTotalCost(tour);

    std::cout << "tour: ";
    for (int node : tour) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Total cost: $" << total_cost << std::endl;

    optimizer.printGraph(tour);

    return 0;
}