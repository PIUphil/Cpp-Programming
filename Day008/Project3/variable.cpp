/*
  변수의 유효범위 : 변수의 소멸시점
  지역변수와 전역변수
*/

#include <iostream>
using namespace std;

int g;					// 전역변수

int add(int x, int y) {		// 전역함수
	// int x = a , int y = b;

	int z;
	//cout << "전역변수 z = " << z << endl;	// 지역변수는 초기화가 필요함. 전역변수는 초기화 안해도됨
	//cout << "전역변수 g = " << g << endl;
	return x + y;
}

int main() {
	int a, b, sum;			// 지역변수

	cout << "두 개의 정수입력 = ";
	cin >> a >> b;

	sum = a + b;
	cout << "sum = " << sum << endl;
	cout << "sum = " << add(a, b) << "\n";
	cout << "전역변수 g = " << g << endl;

	return 0;
}