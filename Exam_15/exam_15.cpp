/*
  연산자(Operator)
  - 피연산자(변수 or 상수) 사이에 계산을 수행하기 위한 기호들
  - 산술연산자 : +, -, *, /(실수몫), %(나머지)
  - 단항연산자와 이항연산자(항 - 변수 or 상수)
*/

#include <iostream>
using namespace std;

int main() {
	int num1 = 10;
	int num2 = 4;

	cout << "+ 연산자에 의한 결괏값 : " << num1 + num2 << endl;
	cout << "- 연산자에 의한 결괏값 : " << num1 - num2 << endl;
	cout << "* 연산자에 의한 결괏값 : " << num1 * num2 << endl;
	cout << "/ 연산자에 의한 결괏값 : " << num1 / num2 << endl;
	cout << "% 연산자에 의한 결괏값 : " << num1 % num2 << endl;

	return 0;
}