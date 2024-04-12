#pragma once
#ifndef  GUARD_Student_info
#define  GUARD_Student_info

#include <iomanip>
#include <string>
#include<vector>
using namespace std;

struct student_info {
	string name;
	double midtrem, final;
	vector<double>homework;

};
bool compare(const student_info&, const student_info&);
istream& read(istream&, student_info&);
istream& read_hw(istream&, vector<double>&);
#endif // ! GUARD_Student_info