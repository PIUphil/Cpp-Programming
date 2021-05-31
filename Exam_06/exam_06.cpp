/*
	함수 오버로딩(Function Overloading)
	- 동일한 이름의 함수를 중복해서 정의하는 것
	- 조건 : 매개변수의 개수가 다르거나 자료형이 달라야 한다.
	- 함수를 호출할 때 함수의 이름과 매개변수의 정보까지 참조해서 호출하기때문에..
*/

#include<iostream>
using namespace std;

int function(void) {  // 매개변수에 void -> 매개변수를 받을게 없다 -> 생략가능
	return 10;
}

int function(int a) {
	return a;
}

int function(int a, int b) {

	return a + b;
}

float function(float a) {

	return a;
}
// 똑같은 이름의 함수더라도, 매개변수의 이름이나 타입이 다르면 사용 가능

int main() {

	cout << function() << endl; // 함수 호출
	cout << function(10, 20) << endl;
	cout << function(3.1f) << endl;

	return 0;
}