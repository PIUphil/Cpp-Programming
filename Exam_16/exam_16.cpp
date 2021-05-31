/*
  사칙연산을 수행하는 프로그램
  두 개의 정수를 입력받아 사칙연산의 결과를 출력하도록 프로그램을 구현하시오.

  <입출력형식>
  수1 = 
  수2 =

  수1 + 수2 = 


*/

#include <iostream>
using namespace std;

int main() {
	// 선언문 : 변수나 상수의 자료형을 선언하는 문장
	int num1, num2;
	int add, sub, mul, div, nmg;
	
	// 입력문
	cout << "수1 = ";
	cin >> num1;
	cout << "수2 = ";
	cin >> num2;

	// 처리문
	add = num1 + num2;
	sub = num1 - num2;
	mul = num1 * num2;
	div = num1 / num2;
	nmg = num1 % num2;

	// 출력문
	cout << num1 << " + " << num2 << " = " << add << endl;
	cout << num1 << " - " << num2 << " = " << sub << endl;
	cout << num1 << " * " << num2 << " = " << mul << endl;
	cout << num1 << " / " << num2 << " = " << div << endl;
	cout << num1 << " % " << num2 << " = " << nmg << endl;

	return 0;
}

