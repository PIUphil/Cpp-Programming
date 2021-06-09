/*
  this 포인터
  - 포인터, 객체 자신 포인터
  - 클래스의 멤버 함수 내에서만 사용
  - 컴파일러가 선언한 변수(묵시적으로 선언되어있는 변수)
  - 제약사항
	멤버함수가 아닌 함수에서 this 사용 불가
	static 멤버함수에서 this 사용 불가
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle() {
		this->radius = 1;
	}

	Circle(int radius) {
		this->radius = radius;
	}

	void setRadius(int radius) {
		this->radius = radius;
	}

	Circle* func() {
		return this;		// 자신의 주소를 리턴할 때
	}

};

int main() {
	Circle c1;
	Circle c2(2);
	Circle c3(3);
	
	c1.setRadius(4);

	return 0;
}