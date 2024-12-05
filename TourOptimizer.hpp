#ifndef TOUROPTIMIZER_HPP
#define TOUROPTIMIZER_HPP

#include <vector>
#include "Point.hpp"

class TourOptimizer {
public:
    virtual std::vector<int> optimize(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) = 0;
    virtual ~TourOptimizer() = default;
};

#endif // TOUROPTIMIZER_HPP