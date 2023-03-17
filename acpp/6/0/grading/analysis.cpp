// System headers
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>

// Local includes
#include "studentInfo.h"
#include "median.h"
#include "average.h"
#include "analysis.h"
#include "grade.h"

// Using declarations
using std::string;
using std::vector;
using std::ostream;
using std::endl;
using std::domain_error;
using std::remove_copy;
using std::transform;
using std::back_inserter;

// Typedefs

// Grade computation using median of homework
// grades in student homework vector; homework grade
// treated as 0 if no homework turned in
double
gradeMedian(const StudentInfoT& s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0.0);
    }
}

double
medianAnalysis(const vector<StudentInfoT>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), gradeMedian);
    return median(grades);
}

// Grade computation using average of homework
// grades in student homework vector; homework grade
// treated as 0 if no homework turned in
double
gradeAvg(const StudentInfoT& s) {
    return grade(s.midterm, s.final, average(s.homework));
}

double
averageAnalysis(const vector<StudentInfoT>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), gradeAvg);
    return median(grades);
}

// Grade computation using median of non-zero homework
// grades in student homework vector; homework grade
// treated as 0 if no homework turned in
double
gradeOptimisticMedian(const StudentInfoT& s) {
    vector<double> nonZeroHw;
    remove_copy(s.homework.begin(), s.homework.end(),
        back_inserter(nonZeroHw), 0);
    if (nonZeroHw.empty()) {
        return grade(s.midterm, s.final, 0.0);
    } else {
        return grade(s.midterm, s.final, median(nonZeroHw));
    }
}

double
optimisticMedianAnalysis(const vector<StudentInfoT>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), gradeOptimisticMedian);
    return median(grades);
}

void
writeAnalysis(ostream& os, const string& analysisDesc,
    double analysis(const vector<StudentInfoT>&),
    const vector<StudentInfoT>& did, const vector<StudentInfoT>& didnot) {
    os << endl;
    os << analysisDesc << " : median(did) : " << analysis(did) << endl;
    os << analysisDesc << " : median(didnot) : " << analysis(didnot) << endl;
}

void
writeAllAnalysis(ostream& os, const vector<StudentInfoT>& did,
    const vector<StudentInfoT>& didnot) {
    writeAnalysis(os, "median", medianAnalysis, did, didnot);
    writeAnalysis(os, "average", averageAnalysis, did, didnot);
    writeAnalysis(
        os, "optimistic median", optimisticMedianAnalysis, did, didnot);
}

double
gradeAnalysis(const vector<StudentInfoT>& students,
    double gradingPolicyFn(const StudentInfoT&)) {
    vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), gradingPolicyFn);
    return median(grades);
}

void
writeAnalysis(ostream& os, const string& type,
    double gradingPolicyFn(const StudentInfoT&),
    const vector<StudentInfoT>& did, const vector<StudentInfoT>& didnot) {
    os << endl;
    os << type << " : median(did) : "
        << gradeAnalysis(did, gradingPolicyFn) << endl;
    os << type << " : median(didnot) : "
        << gradeAnalysis(didnot, gradingPolicyFn) << endl;
}

void
writeAllAnalysisModified(ostream& os, const vector<StudentInfoT>& did,
    const vector<StudentInfoT>& didnot) {
    writeAnalysis(os, "median", gradeMedian, did, didnot);
    writeAnalysis(os, "average", gradeAvg, did, didnot);
    writeAnalysis(
        os, "optimistic median", gradeOptimisticMedian, did, didnot);
}
