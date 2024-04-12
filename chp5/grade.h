#pragma once

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <list>
#include "student_info.h"

bool fgrade(const student_info&);
double grade(double, double, double);
double grade(double, double, vector<double>&);
double grade(const student_info&);
list<student_info> extract_fails(list<student_info>& student);
#endif