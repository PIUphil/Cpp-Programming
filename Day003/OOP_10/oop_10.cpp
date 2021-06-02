/*
  참조변수 == NickName
  - 이미 선언된 변수의 별명을 만드는 기능
  - &연산자를 사용한다.
  - 선언시 반드시 초기화되어있어야 한다.
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return radius * radius * 3.14; }
	void setRadius(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
};

int main() {
	int num = 5;
	int& ref = num;		// '참조변수'는 반드시 초기화를 해야한다.
						// 주소 복사. 별명.
	ref++;

	cout << "num = " << num << endl;
	cout << "ref = " << ref << endl;

	return 0;
}