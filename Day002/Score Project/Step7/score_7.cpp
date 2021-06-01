/*
  7단계 : 구조체를 활용할 것
*/

#include <iostream>
//#include <string>
using namespace std;

struct Student {
	int kor, eng, math, tot;
	float avg;
	// char grade;
};

int main() {
	Student stu[3];

	for (int i = 0; i < 3; i++) {
		cout << "국어 = ";
		cin >> stu[i].kor;
		cout << "영어 = ";
		cin >> stu[i].eng;
		cout << "수학 = ";
		cin >> stu[i].math;

		stu[i].tot = stu[i].kor + stu[i].eng + stu[i].math;
		stu[i].avg = stu[i].tot / 3.0f;
	}

	for (int i = 0; i < 3; i++) {
		cout << "총점 = " << stu[i].tot << ", 평균 = " << stu[i].avg << endl;
	}
	return 0;
}
