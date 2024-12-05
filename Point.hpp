#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b);

#endif // POINT_HPP