/*
  const의 위치와 의미 그리고 사용법
  - const(=constant) : 상수, 변하지 않는 수(고정 수)
*/

#include <iostream>
using namespace std;

int main() {
	const int num = 10;  // const라는 키워드를 사용하여, 변경할 수 없게 바뀜
	// int const num 이라고 써도 됨
	
	// num = 20; <- num을 못바꿈

	cout << num << endl;

	return 0;
}