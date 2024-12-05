#include "NearestNeighborOptimizer.hpp"
#include <limits>

std::vector<int> NearestNeighborOptimizer::optimize(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) {
    int n = points.size();
    std::vector<int> tour;
    std::vector<bool> visited(n, false);

    tour.push_back(0);
    visited[0] = true;

    for (int i = 1; i < n; ++i) {
        int last = tour.back();
        double bestDist = std::numeric_limits<double>::max();
        int best = -1;

        for (int neighbor : graph[last]) {
            if (!visited[neighbor]) {
                double d = distance(points[last], points[neighbor]);
                if (d < bestDist) {
                    bestDist = d;
                    best = neighbor;
                }
            }
        }

        if (best == -1) {
            // Если все соседи уже посещены, ищем среди всех точек
            for (int j = 0; j < n; ++j) {
                if (!visited[j]) {
                    double d = distance(points[last], points[j]);
                    if (d < bestDist) {
                        bestDist = d;
                        best = j;
                    }
                }
            }
        }

        tour.push_back(best);
        visited[best] = true;
    }

    return tour;
}