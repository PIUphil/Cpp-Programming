/*
  2단계 : 성적 처리 프로그램
  국어, 영어, 수학점수를 이용해서 총점과 평균을 계산한다.
  평균을 이용해서 학점을 구현한다.(90-A 80-B 70-C 60-D F)
  (다중if문)
*/

#include <iostream>
using namespace std;

int main() {
	int kor, eng, math, tot;
	float avg;
	char grade;

	cout << "kor = ";
	cin >> kor;
	cout << "eng = ";
	cin >> eng;
	cout << "math = ";
	cin >> math;

	tot = kor + eng + math;
	avg = tot / 3.0f;

	if (avg >= 90) grade = 'A';
	else if (avg >= 80) grade = 'B';
	else if (avg >= 70) grade = 'C';
	else if (avg >= 60) grade = 'D';
	else grade = 'F';

	cout << "총점 = " << tot << ", 평균 = " << avg << endl;
	cout << "학점 = " << grade << endl;

	return 0;
}