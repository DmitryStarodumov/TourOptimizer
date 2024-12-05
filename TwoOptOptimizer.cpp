#include "TwoOptOptimizer.hpp"
#include "NearestNeighborOptimizer.hpp"
#include <algorithm>
#include <limits>

std::vector<int> TwoOptOptimizer::optimize(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) {
    std::vector<int> tour = nearestNeighbor(points, graph);
    int n = tour.size();
    bool improved = true;
    std::mutex mtx;

    while (improved) {
        improved = false;
        std::vector<std::thread> threads;
        int chunkSize = n / NUM_THREADS;

        for (int t = 0; t < NUM_THREADS; ++t) {
            int start = t * chunkSize + 1;
            int end = (t == NUM_THREADS - 1) ? n : (t + 1) * chunkSize + 1;
            threads.emplace_back(&TwoOptOptimizer::twoOptThread, this, std::cref(points), std::ref(tour), start, end, std::ref(mtx), std::ref(improved));
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }

    return tour;
}

std::vector<int> TwoOptOptimizer::nearestNeighbor(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) {
    NearestNeighborOptimizer nnOptimizer;
    return nnOptimizer.optimize(points, graph);
}

void TwoOptOptimizer::twoOptSwap(std::vector<int>& tour, int i, int k) {
    std::reverse(tour.begin() + i, tour.begin() + k + 1);
}

void TwoOptOptimizer::twoOptThread(const std::vector<Point>& points, std::vector<int>& tour, int start, int end, std::mutex& mtx, bool& improved) {
    int n = tour.size();
    for (int i = start; i < end - 1; ++i) {
        for (int k = i + 1; k < n; ++k) {
            double delta = distance(points[tour[i - 1]], points[tour[k]]) +
                           distance(points[tour[i]], points[tour[(k + 1) % n]]) -
                           distance(points[tour[i - 1]], points[tour[i]]) -
                           distance(points[tour[k]], points[tour[(k + 1) % n]]);

            if (delta < 0) {
                std::lock_guard<std::mutex> lock(mtx);
                twoOptSwap(tour, i, k);
                improved = true;
            }
        }
    }
}