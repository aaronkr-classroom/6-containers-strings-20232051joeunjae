#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <list>
#include <vector>
#include <stdexcept>
//학생의 과락 여부를 겨정하는 서술 함수
bool fgrade(const student_info& s) {

	return grade(s) < 60;
}




double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}
double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("no homework!");
	return grade(mt, ft, median(hw));
}



double grade(const student_info& s) {
	return grade(s.midtrem, s.final, s.homework);
}

//세 번째 버전 
//인덱스 대신 반복자를 사용하지만 여전히 
//성증 저하가 우려됨
list<student_info> extract_fails(list<student_info>& student) {
	list<student_info> fail;
	list<student_info> ::iterator iter = student.begin();
		while (iter != student.end()) {
			if (fgrade(*iter)) {
				fail.push_back(*iter);
				iter = student.erase(iter);
			}
			else {
				++iter;

			}
		
		
		
		}
		return fail;
}
