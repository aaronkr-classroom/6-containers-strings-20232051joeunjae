//student_info.cpp
#include "student_info.h"

bool compare(const student_info& x, const student_info& y) {
	return x.name < y.name; // t/f (a-z)

}




istream& read(istream& is, student_info& s) {
	//�л��� �̸�, �߰���� ����, �⸻��� ������ �о� ����
	is >> s.name >> s.midtrem >> s.final;
	//���� ������ ����
	read_hw(is, s.homework);
	return is; //return is ,s;
}
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {


		hw.clear();

		double x;
		//�Һ���
		while (in >> x) {

			hw.push_back(x);
		}

		in.clear();

	}
	return in;
}