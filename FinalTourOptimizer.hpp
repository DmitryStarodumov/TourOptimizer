#ifndef FINALTOUROPTIMIZER_HPP
#define FINALTOUROPTIMIZER_HPP

#include <vector>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

#include "TourOptimizer.hpp"

const double COST_PER_UNIT = 10.0; // по условию задачи единица расстояния будет стоить 10 USD.

class FinalTourOptimizer : public TourOptimizer {
public:
    FinalTourOptimizer(std::vector<Point>& points);
    std::vector<int> optimize(const int start_node, const int end_node) override;
    double getTotalCost(const std::vector<int>& path) const;
    void printGraph(const std::vector<int>& path) const;

private:
    std::vector<Point> points_;
    std::vector<Edge> edges_;
    void generateGraph();
};

#endif