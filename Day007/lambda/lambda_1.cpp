/*
  C++ 람다식의 구성
  - 캡쳐 리스트 : 람다식에서 사용하고자 하는 함수 바깥의 변수 목록
  - 매개변수들()
  - 리턴타입 -> : 생략가능
  - 함수 내용정의부 { ... } : 람다식의 함수 코드
  int func(int x, int y) return x+y;
  [](int x, int y) -> int {return x+y;};	// 람다표현식

  void func(int x, int y) cout << x+y;
  [](int x, int y) {cout << x+y;};			// 람다표현식

  [](int x, int y) {cout << x+y;}(2,3);		// 5
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	[](int x, int y) {cout << x + y; }(2, 3);
	cout << endl;

	auto love = [](string a, string b) {		// 람다식의 변수 타입을 지정할 수 없음.. auto써야함; 컴파일러가 알아서 지정해줌
		cout << a << "보다 " << b << "가 좋아" << endl; 
	};

	love("냉면", "만두");

	return 0;
}