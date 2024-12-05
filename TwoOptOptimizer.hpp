#ifndef TWOOPTOPTIMIZER_HPP
#define TWOOPTOPTIMIZER_HPP

#include "TourOptimizer.hpp"
#include <thread>
#include <mutex>

const int NUM_THREADS = 4;

//для улучшения тура с помощью алгоритма 2-opt
//инфо по алгоритму я взял из вики https://en.wikipedia.org/wiki/2-opt#External_links
class TwoOptOptimizer : public TourOptimizer {
public:
    std::vector<int> optimize(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph) override;

private:
    std::vector<int> nearestNeighbor(const std::vector<Point>& points, const std::vector<std::vector<int>>& graph);
    void twoOptSwap(std::vector<int>& tour, int i, int k);
    void twoOptThread(const std::vector<Point>& points, std::vector<int>& tour, int start, int end, std::mutex& mtx, bool& improved);
};

#endif // TWOOPTOPTIMIZER_HPP