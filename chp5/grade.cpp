#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <list>
#include <vector>
#include <stdexcept>
//�л��� ���� ���θ� �����ϴ� ���� �Լ�
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

//�� ��° ���� 
//�ε��� ��� �ݺ��ڸ� ��������� ������ 
//���� ���ϰ� �����
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
