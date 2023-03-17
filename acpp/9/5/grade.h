#ifndef _GRADE_H_
#define _GRADE_H_

// System headers
#include <vector>
#include <string>

// Local includes

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::string passFailGrade(double, double);

#endif /* _GRADE_H_ */
