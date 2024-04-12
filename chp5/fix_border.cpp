#include <cctype>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

size_t width(const vector<string>& v) {
    size_t maxlen = 0;
    for (size_t i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    size_t maxlen = width(v);
    string border(maxlen + 4, '*');
   
    //상단 테두리 추가
    ret.push_back(border);
    
    //문자열울 각각 별표와  공백으로 둘러싼 후 벡터에 추가
    for (size_t i = 0; i != v.size(); ++i) {
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
        ret.push_back(*it); //반복자 사용하면 역참조 해야함
    }
    return ret;
}

//수평 결합
vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;
    //두문자 사이에 공백을 남김
    size_t width1 = width(left) + 1;
    //왼쪽 문자그림과 오른쪽 문자 그림의 요소를 살펴보는 인덱스
    size_t i = 0, j = 0;
    while (i != left.size() || j != right.size()) {
        //두문자 그림의 문자들을 저장할 새로운 문자열을 생성
         
           string s;
        //원쪽 문자 그림에서 행 하나를 복사
        if (i != left.size()) {
            s = left[i++];
        }
        s += string(width1 - s.size(), ' ');
        if (j != right.size()) {
            s += right[j++];
        }
        ret.push_back(s);
    }
    return ret;
}

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string s;
    vector<vector<string>> frames;

    while (getline(std::cin, s)) {
        vector<string> v = split(s, ' ');
        frames.push_back(frame(v));
    }

    ofstream outFile("out.txt");
    if (!outFile) {
        cerr << "Error: Unable to open out.txt for writing!" << endl;
        return 1;
    }

    for (const auto& f : frames) {
        for (const auto& line : f) {
            outFile << line << endl;
        }
    }
    outFile.close();
    cout << "Output saved to out.txt" << endl;

    return 0;
}