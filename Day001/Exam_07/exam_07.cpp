/*
  default parameter : 디폴트 매개변수
  - 매개변수에 처음 값을 설정하는 기능
  - 함수의 오버로딩의 확장형이라고 생각해도 됨
*/

#include<iostream>
using namespace std;

int function(int a = 10) {
	return a;
}

int main() {

	cout << function() << endl;
	cout << function(100) << endl;

	return 0;
}

