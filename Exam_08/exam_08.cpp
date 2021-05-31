/*
  매크로 함수의 인라인 함수화     // 매크로함수가 c++로 넘어오면서 인라인(in line)함수 화 된 것..
  - 장점 : 실행 속도가 빠르다.
  - 단점 : 한 줄에 기술해야한다.
*/

#include <iostream>
#define SQUARE(x) (x * x)	// 매크로 함수 // 자료형이 없음?! - 자료형에 독립적임
using namespace std;

inline int SSS(int x) {		// 인라인 함수 (inline 예약어)
	return x * x;
}

/*inline float SSS(float x) {
	return x * x;
}*/

int main() {
	cout << SQUARE(5.1f) << endl;  
	cout << SSS(5.1f) << endl;
	return 0;
}