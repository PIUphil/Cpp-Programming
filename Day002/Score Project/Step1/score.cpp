/*
  1단계 : 성적처리 프로그램
  국어, 영어, 수학 점수를 입력받아 총점과 평균을 출력하는 프로그램
*/

#include <iostream>
using namespace std;

int main() {
	int kor, eng, math, tot;
	float avg;

	cout << "kor = ";
	cin >> kor;
	cout << "eng = ";
	cin >> eng;
	cout << "math = ";
	cin >> math;

	tot = kor + eng + math;
	avg = tot / 3.0f;

	cout << "총점 = " << tot << ", 평균 = " << avg << endl;


	return 0;
}