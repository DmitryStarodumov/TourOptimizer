#ifndef NEARESTNEIGHBOROPTIMIZER_HPP
#define NEARESTNEIGHBOROPTIMIZER_HPP

#include <limits>
#include <vector>
#include <algorithm>

#include "TourOptimizer.hpp"

//для начального построения тура
class NearestNeighborOptimizer : public TourOptimizer {
public:
    std::vector<int> optimize(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) override;
};

#endif // NEARESTNEIGHBOROPTIMIZER_HPP  