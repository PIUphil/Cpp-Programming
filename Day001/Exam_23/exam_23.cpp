/*
  국어, 영어, 수학 점수를 입력받아 총점과 평균을 계산하여 출력한 후
  평균을 이용하여 학점을 부여한다.
  학점은 평균이 90점 이상이면 'A학점', 80점 이상이면 'B학점',
  70점 이상이면 'C학점', 60점 이상이면 'D학점', 이외는 'F학점'이
  출력되도록 구현한다.
  단, 주어진 입출력 형식에 맞게 프로그램을 구현할 것.

  <입력형식>
  국어 = 
  영어 = 
  수학 = 

  총점 : xx, 평균 : xx, 학점 : xx
*/

#include <iostream>
using namespace std;
int main() {

	int kor, eng, math, tot, avg;
	string grade;

	cout << "국어 = ";
	cin >> kor;
	cout << "영어 = ";
	cin >> eng;
	cout << "수학 = ";
	cin >> math;

	tot = kor + eng + math;
	avg = tot / 3;

	if (avg >= 90)
		grade = "A학점";
	else if(avg >= 80)
		grade = "B학점";
	else if(avg >= 70)
		grade = "C학점";
	else if(avg >= 60)
		grade = "D학점";
	else
		grade = "F학점";

	cout << "총점 : " << tot << ", 평균 : " << avg << ", 학점 : " << grade << endl;

	return 0;
}