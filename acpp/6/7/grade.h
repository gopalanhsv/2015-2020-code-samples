#ifndef _GRADE_H_
#define _GRADE_H_

// System headers
#include <vector>

// Local includes
#include "studentInfo.h"

double grade(double, double, double);

double grade(double, double, const std::vector<double>&);

double grade(const StudentInfoT&);

#endif /* _GRADE_H_ */
