//student_info.cpp
#include "student_info.h"

bool compare(const student_info& x, const student_info& y) {
	return x.name < y.name; // t/f (a-z)

}




istream& read(istream& is, student_info& s) {
	//학생의 이름, 중간고사 점수, 기말고사 점수를 읽어 저장
	is >> s.name >> s.midtrem >> s.final;
	//과제 점수를 읽음
	read_hw(is, s.homework);
	return is; //return is ,s;
}
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {


		hw.clear();

		double x;
		//불변성
		while (in >> x) {

			hw.push_back(x);
		}

		in.clear();

	}
	return in;
}