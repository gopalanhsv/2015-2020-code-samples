#ifndef _POINT_H_
#define _POINT_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Point {
public:
    // Constructor
    Point(int x, int y) : _x(x), _y(y), _sqrdDist(0) {
        _sqrdDist =  (_x * _x) + (_y * _y);
    }

    // Accessors
    inline int x() const { return _x; }
    inline int y() const { return _y; }
    inline long squaredDistFromOrigin() const { return _sqrdDist; }

private:
    Point();

    int _x;
    int _y;
    int _sqrdDist; // Distance from origin(0,0)
};

class PointsArray {
public:
    static std::vector<Point>
    kClosestPointsToOrigin(const std::vector<Point>& pv, unsigned long k);

private:
};

#endif /* _POINT_H_ */
