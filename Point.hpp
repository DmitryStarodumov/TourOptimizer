#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    double x, y;
};

struct Edge {
    int start, end;
    double weight;
};

double distance(const Point& a, const Point& b);

#endif // POINT_HPP