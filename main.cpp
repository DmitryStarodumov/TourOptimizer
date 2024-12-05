#include <iostream>
#include <vector>
#include <algorithm> // Для std::find и std::rotate
#include "Point.hpp"
#include "NearestNeighborOptimizer.hpp"
#include "TwoOptOptimizer.hpp"
#include "utils.hpp"

const int NUM_POINTS = 100; //общее количество точек
const double RADIUS = 10.0; //радиус окружности по условию не определен, поэтому используем 10 по дефолту

int main() {
    std::vector<Point> points = generatePoints(NUM_POINTS, RADIUS);

    int destination;
    std::cout << "Enter the destination point index (1 to " << NUM_POINTS - 1 << "): ";
    std::cin >> destination;

    if (destination < 1 || destination >= NUM_POINTS) {
        std::cerr << "Invalid destination point index." << std::endl;
        return 1;
    }

    // Создаем граф, где каждая точка соединена с ближайшими соседями
    std::vector<std::vector<int>> graph(NUM_POINTS);
    for (int i = 0; i < NUM_POINTS; ++i) {
        std::vector<std::pair<double, int>> distances;
        for (int j = 0; j < NUM_POINTS; ++j) {
            if (i != j) {
                distances.push_back({distance(points[i], points[j]), j});
            }
        }
        std::sort(distances.begin(), distances.end());
        int num_neighbors = 2 + rand() % 5; // генерируем случайное число соседей от 2 до 6
        for (int k = 0; k < std::min(num_neighbors, (int)distances.size()); ++k) {
            graph[i].push_back(distances[k].second);
        }
    }

    // Используем NearestNeighborOptimizer для начального тура
    NearestNeighborOptimizer nnOptimizer;
    std::vector<int> tour = nnOptimizer.optimize(points, graph);

    // Убедимся, что тур заканчивается в указанном пользователем пункте назначения
    auto it = std::find(tour.begin(), tour.end(), destination);
    if (it != tour.end()) {
        std::rotate(tour.begin(), it, tour.end());
    }

    // Оптимизируем тур с помощью TwoOptOptimizer
    TwoOptOptimizer twoOptOptimizer;
    tour = twoOptOptimizer.optimize(points, graph);

    double cost = tourCost(points, tour);

    std::cout << "Tour cost: " << cost << " USD" << std::endl;

    return 0;
}