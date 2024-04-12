#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream> 
#include "grade.h"
#include "student_info.h"

using namespace std;

int main() {
    ifstream student_file("grades.txt");
    vector<student_info> students;
    student_info record;
    string::size_type maxlen = 0;

    while (read(student_file, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);
    for (vector<student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << "final grade" << setprecision(3) << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
    }

    return 0;
}