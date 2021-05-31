/*
  pointer(포인터) : 메모리를 가리키는 키워드
  - 메모리의 주소값을 저장하는 변수(포인터변수)
*/

#include <iostream>
using namespace std;

int main() {
	int a = 10;			// 일반 변수 선언
	int b = 20;
	int* /*const*/ p = &a;  // 포인터 변수 선언 // a의 주소를 담음  // const를 붙이면 p가 상수화 됨

	cout << "a = " << a << endl;
	cout << "p = " << p << endl;
	cout << "p = " << &a << endl;	// & 주소연산자(reference)
	cout << "a = " << *p << endl;	// * 참조연산자(직접 접근 연산자)
	/*
	p = &b;							// 포인터는 변할 수 있음
	cout << "b = " << *p << endl;
	cout << "b = " << p << endl;
	*/
	cout << *p << endl;
	*p = 2;					// 주소에 직접 접근(직접 접근 연산자) // const되면 변경불가
	// const int* p 일 땐, '*p'가 상수화 되어서 다른 값을 담을 수 없음
	// int* const p 일 땐, 'p'가 상수화 되어서 다른 값을 담을 수 없음

	p = &b;
	cout << "*p = " << *p << endl;
	cout << "b = " << p << endl;

	cout << *p << endl;
	cout << "a = " << a << endl;

	return 0;
}