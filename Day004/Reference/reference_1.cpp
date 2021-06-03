/*
  Referecnce : 참조자
  - 자신이 참조하는 변수를 대신할 수 있는 또 다른 이름
  - 기존에 정의된 변수에 다른 이름을 정의하는 것
  - 반드시 참조자를 선언할 때 초기화가 되어있어야 한다.
  - 참조 연산자 : &
*/

#include <iostream>
using namespace std;

int main() {
	int num1 = 1020;
	int& num2 = num1;		// 참조변수 선언

	num2 = 2021;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	cout << "num1주소 = " << &num1 << endl;
	cout << "num2주소 = " << &num2 << endl;

	return 0;
}