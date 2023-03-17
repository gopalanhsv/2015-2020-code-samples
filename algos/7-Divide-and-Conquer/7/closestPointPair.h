#ifndef _CLOSEST_POINT_PAIR_H_
#define _CLOSEST_POINT_PAIR_H_

// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes

// Using declarations

// Statics, globals, typedefs
typedef struct _Point {
    int _x;
    int _y;
} PointT;

typedef std::vector<PointT> PointVecT;

double
closestPointPairDistanceBruteForce(const PointVecT& ptVec);

double
closestPointPairDistanceDivConquer(PointVecT ptVec);

#endif /* _CLOSEST_POINT_PAIR_H_ */
