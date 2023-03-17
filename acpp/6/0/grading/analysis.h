#ifndef _ANALYSIS_H_
#define _ANALYSIS_H_

// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "studentInfo.h"

// Typedefs

void writeAllAnalysis(std::ostream&,
    const std::vector<StudentInfoT>&, const std::vector<StudentInfoT>&);

void writeAllAnalysisModified(std::ostream&,
    const std::vector<StudentInfoT>&, const std::vector<StudentInfoT>&);

#endif /* _ANALYSIS_H_ */
