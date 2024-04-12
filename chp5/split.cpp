#include <cctype>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_type;
    string_type i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i])) {
            ++i;
        }

        string_type j = i;

        while (j != s.size() && !isspace(s[j])) {
            ++j; // j++ ��� ++j�� ����Ͽ� j�� ������Ŵ
        }

        if (i != j) {
            // i�������� j-i���� ���ڸ� s�� ����
            ret.push_back(s.substr(i, j - i));
            i = j; // ���� �ܾ��� �������� �̵�
        }
    }

    return ret; // ���� ��ȯ�� ���⿡ ��ġ�ؾ� ��
}
int main() {
    string s;

    while (getline(cin, s)) {
        vector<string> v = split(s);
        //���� v�� ������ �ܾ ���� ���
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
    return 0;
}