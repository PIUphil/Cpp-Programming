/*
  동적 메모리 할당 : 동적으로 메모리를 할당받아 사용하는 것
  - heap 영역에 저장된다. => 스택(stack)
  - c : malloc() / free()
  - c++ : new / delete
  - 기타언어 : new
*/

#include <iostream>
using namespace std;

int main() {
	// 정수 한 개를 저장하는 동적할당 메모리를 선언
	int* p = new int;			// 4byte

	*p = 10;

	cout << *p << endl;

	delete p;					// 동적할당 메모리 반환
	return 0;
}