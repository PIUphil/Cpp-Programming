/*
  배열(Array)
  - 동질의 자료형을 하나의 이름으로 묶어서 관리하는 자료구조
  - 기억장소의 낭비를 줄이고, 처리속도를 빠르게 하기 위해.
  - 1차원 배열과 다차원 배열(2차원 배열...)
  - 배열을 선언
	int a;
	int arr[배열의 길이];   // ['첨자'] 
  - 배열의 인덱스는 0부터 시작한다

  - 변수(variable)
  - 배열(Array)
  - 구조체(structure) : 서로 다른 자료형을 하나의 이름으로 묶는 자료구조
  - 클래스(class)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// int a, b, c;
	int arr[3];			// 배열 - 4바이트x3 // 연속된 공간에 위치
	/*a = 10;
	b = 20;
	c = 30;*/
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;		// 배열을 비워두면 쓰레기값이 들어감;;


	/*cout << sizeof(int) << "bytes" << endl;	
	cout << a << " : " << &a << endl;
	cout << b << " : " << &b << endl;
	cout << c << " : " << &c << endl;*/

	cout << sizeof(arr) << "bytes" << endl;
	/*cout << arr[0] << " : " << &arr[0] << endl;
	cout << arr[1] << " : " << &arr[1] << endl;
	cout << arr[2] << " : " << &arr[2] << endl;*/
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " : " << &arr[i] << endl;
	}

	return 0;
}