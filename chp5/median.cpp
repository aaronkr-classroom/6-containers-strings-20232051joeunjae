#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;


double median(vector<double>vec) {
	//���� ������ �Է� ������ Ȯ��
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0) {
		throw domain_error("median of an emtpy vector");
	}
	//������ ����
	sort(vec.begin(), vec.end());

	//���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	double median;
	return size % 2 == 0;
	median = size % 2 == 0 ?
		(vec[mid] + vec[mid - 1]) / 2
		: vec[mid];
}