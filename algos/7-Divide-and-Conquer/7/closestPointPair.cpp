// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>

// Local includes
#include "closestPointPair.h"

// Using declarations
using std::vector;
using std::sort;
using std::min;
using std::domain_error;

// Statics, globals, typedefs
typedef vector<PointT>::size_type vecSzT;

double
closestPointPairDistanceBruteForce(const PointVecT& ptVec) {
    if (ptVec.empty()) {
        throw domain_error("Error! Empty input point vector!");
    }

    double minDistSqrd = std::numeric_limits<double>::max();
    // Iterate over all points. For each point compute the distance
    // to every other point. Take the minimum distance
    for (vecSzT i = 0; i != ptVec.size(); ++i) {
        const PointT& x = ptVec[i];
        for (vecSzT j = i + 1; j != ptVec.size(); ++j) {
            const PointT& y = ptVec[j];
            // Compute the distance between points x & y
            double distSqrd =
                (y._x - x._x) * (y._x - x._x) + (y._y - x._y) * (y._y - x._y);
            // Update min distance 
            minDistSqrd = min(distSqrd, minDistSqrd);
        }
    }

    return pow(minDistSqrd, 0.5);
}

bool
compareXCoord(const PointT& p1, const PointT& p2) {
    return p1._x < p2._x;
}

bool
compareYCoord(const PointT& p1, const PointT& p2) {
    return p1._y < p2._y;
}

// Compute the distance between the closest pair of points in residing in
// a vertical strip of length [-d, +d] around the vertical line passing
// through the point at index 'mid' in given vector of points
// (sorted based on X coord)
double
closestPointPairDistInVerticalStrip(PointVecT& ptVec, vecSzT mid, double d) {
    // Determine the set of point lying in a vertical strip [-d, +d] around
    // point at given index 'mid'
    PointVecT stripPoints;
    for (vecSzT i = 0; i != ptVec.size(); ++i) {
        if (abs(ptVec[i]._x - ptVec[mid]._x)  <= d) {
            stripPoints.push_back(ptVec[i]);
        }
    }

    // Sort the points in vertical strip based on their Y coords
    sort(stripPoints.begin(), stripPoints.end(), compareYCoord);

    // Closest pair of points within the vertical strip have the property
    // that for each point in the vertical strip, the closest point will be
    // one amongst the 5 nearest points to it as per the Y coordinate
    // (geometric property)

    // So minimum distance between closest pair of points will be found
    // by finding the distance from each point A in the vertical strip to
    // 5 of its nearest neighbours; taking the minimum of this value will
    // give distance to closest point from A.
    // The above has to be done for each point in the vertical strip
    double minDistSqrd = std::numeric_limits<double>::max();
    for (vecSzT i = 0; i != ptVec.size(); ++i) {
        const PointT& x = ptVec[i];
        for (vecSzT j = i + 1; j != ptVec.size() && j <= i + 5; ++j) {
            const PointT& y = ptVec[j];
            // Compute the distance between points x & y
            double distSqrd =
                (y._x - x._x) * (y._x - x._x) + (y._y - x._y) * (y._y - x._y);
            // Update min distance 
            minDistSqrd = min(distSqrd, minDistSqrd);
        }
    }

    return pow(minDistSqrd, 0.5);
}

// Compute the distance between the closest pair of points in
// the given vector (points sorted based on X coord) in the 
// range bound by indices [lo, hi]
double
closestPointPairDistRecursive(PointVecT& ptVec, vecSzT lo, vecSzT hi) {
    // Number of points in the range
    vecSzT n = hi - lo + 1;
    // Number of points less than 4, adopt brute force approach
    if (n <= 3) {
        return closestPointPairDistanceBruteForce(ptVec);
    }

    // Find midpoint element in the given range
    vecSzT mid = lo + n / 2;

    // Split range [lo, hi] under examination for closest point pair into
    // two halves by having a vertical line pass through the midpoint of
    // the range

    // Compute min distance between closest point pairs in the region to
    // the left of vertical line
    double minL = closestPointPairDistRecursive(ptVec, lo, mid);

    // Compute min distance between closest point pairs in the region to
    // the right of vertical line
    double minR = closestPointPairDistRecursive(ptVec, mid + 1, hi);

    // Min of closest point pair distance to the left and right of
    // vertical line
    double minLR = min(minL, minR);

    // Consider all points lying in the vertical strip lying in the region
    // [-minLR, +minLR] around the vertical line through the midpoint
    // Find the distance of closest point pair for points lying in this
    // strip
    double minStrip = closestPointPairDistInVerticalStrip(ptVec, mid, minLR);

    // Closest pair of points in the range of [lo, hi] would be the closest
    // of the point pairs to the left of midpoint OR right of midpoint OR
    // in the above vertical strip around mid point
    return min(minLR, minStrip);
}

double
closestPointPairDistanceDivConquer(PointVecT ptVec) {
    if (ptVec.empty()) {
        throw domain_error("Error! Empty input point vector!");
    }

    // Sort points in ascending order based on their X-axis coordinates
    sort(ptVec.begin(), ptVec.end(), compareXCoord);

    return closestPointPairDistRecursive(ptVec, 0, ptVec.size() - 1);
}
