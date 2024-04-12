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
            ++j; // j++ 대신 ++j를 사용하여 j를 증가시킴
        }

        if (i != j) {
            // i에서부터 j-i개의 문자를 s에 복사
            ret.push_back(s.substr(i, j - i));
            i = j; // 다음 단어의 시작으로 이동
        }
    }

    return ret; // 벡터 반환은 여기에 위치해야 함
}
int main() {
    string s;

    while (getline(cin, s)) {
        vector<string> v = split(s);
        //벡터 v에 저장한 단어를 각각 출력
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
    return 0;
}