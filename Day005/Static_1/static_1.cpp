/*
  지정예약어 static
  - 전역변수의 static : 해당 파일에서만 참조를 허용한다는 의미
  - 지역변수의 static : 한번만 초기화되고, 일반적인 지역변수와 달리 함수를 벗어나도 소멸되지 않는다.
*/

#include <iostream>
using namespace std;

// static으로 선언된 변수는 전역변수와 마찬가지로 초기화되지 않으면 0으로 초기화된다.

void counter() {
	static int cnt;		// 0으로 초기화됨(자동) -> 소멸하지 않으므로 cnt값이 계속 누적됨
	//int cnt = 0;		// 계속 1이 출력됨
	cnt++;
	cout << "Current cnt = " << cnt << endl;
}

//int x;				// 전역변수 - 기본적으로 0으로 초기화됨

int main() {
	//int y = 0;		// 지역변수 - 초기화 해줘야함

	for (int i = 0; i < 10; i++)
		counter();
	
	/*cout << "x = " << x << endl;
	cout << "y = " << y << endl;*/
	return 0;
}