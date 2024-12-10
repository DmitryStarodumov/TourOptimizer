#include "FinalTourOptimizer.hpp"
#include <iostream>

FinalTourOptimizer::FinalTourOptimizer(std::vector<Point>& points) : points_(points) {
    generateGraph();
}

std::vector<int> FinalTourOptimizer::optimize(const int start_node, const int end_node) {
    // Greedy approach (replace with better algorithm for optimal solution)
    std::vector<int> tour;
    std::vector<bool> visited(points_.size(), false);
    std::vector<int> unvisited;
    for (int i = 0; i < points_.size(); ++i) unvisited.push_back(i);

    tour.push_back(start_node);
    visited[start_node] = true;
    unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), start_node), unvisited.end());

    int current_node = start_node;
    while (!unvisited.empty()) {
        int next_node = -1;
        double min_distance = std::numeric_limits<double>::infinity();
        for (int node_index : unvisited) {
            double dist = distance(points_[current_node], points_[node_index]);
            if (dist < min_distance) {
                min_distance = dist;
                next_node = node_index;
            }
        }
        tour.push_back(next_node);
        visited[next_node] = true;
        unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), next_node), unvisited.end());
        current_node = next_node;
    }
    tour.push_back(end_node);
    return tour;
}

double FinalTourOptimizer::getTotalCost(const std::vector<int>& tour) const {
    double total_cost = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        total_cost += distance(points_[tour[i]], points_[tour[i + 1]]);
    }
    return total_cost * COST_PER_UNIT;
}

void FinalTourOptimizer::printGraph(const std::vector<int>& tour) const {
    // Print edges in the order of the tour
    std::cout << "Tour Edges:\n";
    double total_weight = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        int start = tour[i];
        int end = tour[i + 1];
        double weight = distance(points_[start], points_[end]);
        total_weight += weight;
        std::cout << "Edge: " << start << " - " << end << "  Weight: " << weight << std::endl;
    }
    std::cout << "total_weight: " << total_weight << std::endl;
}


void FinalTourOptimizer::generateGraph() {
    // Sort points based on their angle around the circle
    std::vector<std::pair<double, int>> angles(points_.size());
    for (size_t i = 0; i < points_.size(); ++i) {
        angles[i] = {std::atan2(points_[i].y, points_[i].x), (int)i};
    }
    std::sort(angles.begin(), angles.end());

    // Connect each point to its two immediate neighbors
    for (size_t i = 0; i < angles.size(); ++i) {
        int start = angles[i].second;
        int end1 = angles[(i + 1) % angles.size()].second;
        int end2 = angles[(i + angles.size() - 1) % angles.size()].second;
        edges_.push_back({start, end1, distance(points_[start], points_[end1])});
        edges_.push_back({start, end2, distance(points_[start], points_[end2])});
    }

    // Optionally connect each point to up to four additional neighbors
    for (size_t i = 0; i < angles.size(); ++i) {
        int start = angles[i].second;
        for (int j = 2; j <= 3; ++j) {
            int end1 = angles[(i + j) % angles.size()].second;
            int end2 = angles[(i + angles.size() - j) % angles.size()].second;
            edges_.push_back({start, end1, distance(points_[start], points_[end1])});
            edges_.push_back({start, end2, distance(points_[start], points_[end2])});
        }
    }
}