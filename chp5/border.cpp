#include <cctype>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }

    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // 상단 테두리 추가
    ret.push_back(border);

    // 문자열을 각각 별표와 공백으로 둘러싼 후 벡터에 추가
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    // 하단 테두리 추가
    ret.push_back(border);

    return ret;
}
//수직 결합 
 vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    vector<string> ret = top;
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
        ret.push_back(*it);//반복자 사용하면 역함조 해야함
    }
    return ret;
}
 //수평 결합
 vector<string> hcat(const vector<string>& left, const vector<string>& right) {
     vector<string> ret;
     //두문자 사이에 공백을 남김
     string::size_type width1 = width(left) + 1;
     //왼쪽 문자그림과 오른쪽 문자 그림의 요소를 살펴보는 인덱스
     vector<string>::size_type i = 0, j = 0;
     while (i != left.size() || j != right.size()) {
         //두문자 그림의 문자들을 저장할 새로운 문자열을 생성
         string s;

         //원쪽 문자 그림에서 행 하나를 복사
         if (i != left.size()) {
             s = left[i++];
         }
         s += string(width1 - s.size(), ' ');
         if (j != right.size()) {
             s += right[i++];
         }
    
     }
     ret.push_back(s);
     return ret;
 }
 /*
 1. split() 가져오고 사용하기
 2. vcat() 사용하기
 3. hcat() 사용하기
 4. out.txt 파일에서 모든 출력을 저장하기
 */

 int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> v = split(s); //과제 = split()가져오기
        frame(v);

    }

    return 0;
    
}