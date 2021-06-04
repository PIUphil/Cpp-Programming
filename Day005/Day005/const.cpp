/*
  const(= constant, 상수) : 값을 상수로 선언한다.
  - 값을 변경할 수 없도록 한다.
*/
#include <iostream>
using namespace std;

int main() {
	//int num1 = 10;
	//const int num2 = 20;	// #define num2 20

	//num1 = 1;
	//num2 = 2;				// 변경 불가

	int value1 = 5, value2 = 11;
	//const int* ptr = &value1;		// *ptr의 값은 못바꿈. ptr이 가리키는 주소는 변경가능
	//int* const ptr = &value1;		// ptr 변경불가
	const int* const ptr = &value1;	// 둘다못바꿈..

	// value1 = 10;
	*ptr = 10;			// 변경 불가
	ptr = &value2;

	// cout << value1 << " : " << *ptr << endl;	// 10:10
	cout << value1 << " : " << *ptr << endl;

	return 0;
}