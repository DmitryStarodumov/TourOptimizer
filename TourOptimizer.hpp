#ifndef TOUROPTIMIZER_HPP
#define TOUROPTIMIZER_HPP

#include <vector>
#include "Point.hpp"

class TourOptimizer {
public:
    virtual std::vector<int> optimize(const int start_node, const int end_node) = 0;
    virtual ~TourOptimizer() = default;
};

#endif // TOUROPTIMIZER_HPP