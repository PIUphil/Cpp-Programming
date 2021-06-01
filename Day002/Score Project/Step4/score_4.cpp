/*
  4단계 : 각 과목의 점수는 0~100 사이의 값만 입력하되,
  범위를 벗어나면 다시 입력받도록 구현할 것.
*/

#include <iostream>
using namespace std;

int main() {
	int kor, eng, math, tot;
	float avg;
	char grade;
	
	do {
		cout << "kor = ";
		cin >> kor;
	} while (kor < 0 || kor > 100);
	
	do {
		cout << "eng = ";
		cin >> eng;
	} while (eng < 0 || eng > 100);

	do{
	cout << "math = ";
	cin >> math;
	} while (math < 0 || math > 100);


	tot = kor + eng + math;
	avg = tot / 3.0f;

	switch (int(avg) / 10) {
	case 10: case 9: grade = 'A'; break;
	case 8: grade = 'B'; break;
	case 7: grade = 'C'; break;
	case 6: grade = 'D'; break;
	default: grade = 'F';
	}

	cout << "총점 = " << tot << ", 평균 = " << avg << endl;
	cout << "학점 = " << grade << endl;

	return 0;
}