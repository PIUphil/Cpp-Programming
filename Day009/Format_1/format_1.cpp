/*
  ios 클래스에 정의된 포맷 플래그
  - ios::skipws => 입력시 공백문자 무시			// ws=space bar
  - ios::unitbuf => 출력스트림에 들어오는 데이터를 버퍼링하지않고(버퍼에 담지 않고) 바로 출력	
  - ios::uppercase => 16진수(0~9, A~F) 지수표현을 대문자로
  - ios::dec => decimal, 10진수로 출력. 기본값
*/

#include <iostream>
using namespace std;

int main() {
	cout << 30 << endl;			// 10진수로 출력

	cout.unsetf(ios::dec);			// setting값을 해제 - 10진수 해제
	cout.setf(ios::hex);			// 16진수로 출력

	cout << 30 << endl;				// 1e  => 0x1e

	cout.setf(ios::showbase);
	cout << 30 << endl;				// 0x1e

	cout.setf(ios::uppercase);
	cout << 30 << endl;				// 0X1E

	cout.setf(ios::dec | ios::showpoint);		// showpoint - 소수점 표현
	cout << 23.5 << endl;			// 23.5000
			
	cout.setf(ios::scientific);		// 실수 표현을 과학산술용 표현
	cout << 23.5 << endl;			// 2.350000E +001

	cout.setf(ios::showpos);		// 부호도 함께 출력
	cout << 23.5 << endl;			// +2.350000E +001

	return 0;
}