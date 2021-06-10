/*
  입력받은 문자열의 특정 문자 빈도수 출력하는 프로그램
  <처리조건>
  - 문자열을 입력받아 문자의 빈도를 계산하여 출력한다.
  - 입력 문자열은 대소 문자를 구분하지 않는다.
  - 빈도값 =  특정문자의 출현한 수 / 전체 문자의 수
  <예시>
  문자열 = ALL
  A = 1/3
  L = 2/3
  
  문자열 = Hello World
  D(d) = 1/11
  E(e) = 1/11
  H(h) = 1/11
  L(l) = 3/11
  O(o) = 2/11
  R(r) = 1/11
  W(w) = 1/11
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

	char buf[80];
	int count[26] = { 0 };		// A~Z

	cout << "문자열 = ";
	cin.getline(buf, 80);

	char* p = buf;
	int len = 0;
	double rate;

	while (*p != '\0') {
		*p = toupper(*p);	// 대문자로 변환
		if (*p >= 'A' && *p <= 'Z')
			count[*p - 'A']++;
		p++;
	}

	for (int i = 65; i <= 90; i++)
		len += count[i - 'A'];

	cout << "결과" << endl << endl;
	
	for (int i = 0; i < 26; i++) {
		rate = (double)count[i] / double(len);
		if (count[i] != 0)
			cout << (char)('A' + i) << "(" << (char)('a' + i) << ") = " << /*fixed << setprecision(6) <<*/ rate << endl;
	}

	return 0;
}

/*
  [ C++ 강의 ]

  1. c/c++ 기초
	 - 연산자
	 - 제어문(조건문, 반복문)
	 - 배열
	 - 함수
	 - 포인터

  2. 클래스와 객체
	 - 객체 포인터와 객체 배열
	 - 객체 동적 할당
	 - 함수와 참조
	 - 복사생성자
	 - 함수 오버로딩과 오버라이딩
	 - static, const
	 - friend
	 - 연산자 오버로딩 operator+

  3. 객체 지향적인 프로그래밍
	 - 상속
	 - 다형성
	 - 추상 : 가상함수, 순수가상함수, 추상클래스

  4. 템플릿과 STL
	 - 컨테이너 : vector, list, map ...
	 - algorithm
	 - iterator(반복자)

  5. 파일 입출력(I/O)
	 - ios => iostream
	 - istream, ostream
	 - ios => fstream
	 - ifstream(get, write, put, getline), ofstream

*/