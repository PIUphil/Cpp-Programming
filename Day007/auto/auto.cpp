/*
  C++에서 auto
  - 컴파일러에게 변수 선언문에서 추론하여 타입을 자동으로 선언하도록 지시
  - 장점 : 변수 선언을 간결, 긴 타입의 선언을 오타없이 작성
*/

#include <iostream>
using namespace std;

int main() {
	//double pi = 3.141592;
	auto pi = 3.141592;
	auto num = 3;
	auto* p = &num;

	int num2 = 10;
	int& ref = num2;		// 참조자(별명)
	auto ref2 = ref;

	return 0;
}