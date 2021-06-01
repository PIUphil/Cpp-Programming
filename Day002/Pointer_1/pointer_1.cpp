/*
  포인터(Pointer):메모리의 주소를 가리키는 것
  - 포인터변수 : 메모리의 주소값을 저장하는 변수
	 int a;
	 int *p;
  - 접근속도를 빠르게 하기 위해서
  - 배열처럼 대용량 데이터를 담고 있는 자료구조에 함께 사용된다.
  - 포인터 연산 : +/-, ++/--
*/

#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 10, 20, 30, 40, 50 };
	int* p;
	
	p = arr;  // 배열명은 배열의 시작주소와 같다.(&arr[0])

	// cout << "arr[0] = " << arr[2] << endl;
	// cout << "p = " << *(p+2) << endl;

	for (int i=0; i<5; i++)
		cout << *(p+i) << endl;		// 포인터(p) 그대로

	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << *p++ << endl;		// 포인터(p)의 위치가 바뀜

	return 0;
}