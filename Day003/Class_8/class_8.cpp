/*
  접근지정자(or 접근제한자)
  - 객체 지향 언어에서는 객체를 캡슐화하고, 외부에서 접근을 제한한다.
  - private(비공개) : 클래스 내에서만 접근이 허용된다. (기본값)
  - protected(보호) : 상속 관계에서만 접근이 허용된다.
  - public(공개) : 객체(instance)를 생성하면 어디서든 접근이 허용
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;			// private

public:
	Circle();
	Circle(int r);
	double getArea();

	void setRadius(int r);
	int getRadius();
};

Circle::Circle() {
	radius = 1;
}

Circle::Circle(int r) {
	radius = r;
}

double Circle::getArea() {
	return radius * radius * 3.14;
}

void Circle::setRadius(int r) {
	radius = r;
}

int Circle::getRadius() {
	return radius;
}



int main() {
	Circle c;
	// c.radius = 5;		 // radius가 private로 되어있어서 직접접근불가
	c.setRadius(5);
	cout << "반지름 = " << c.getRadius() << endl;
	cout << "넓이 = " << c.getArea() << endl;

	return 0;
}