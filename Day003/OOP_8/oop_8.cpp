/*
  함수와 참조, 복사 생성자
  함수 호출 : Call By Name 
			  Call By Value, Call By Reference
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

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
	cout << c.getRadius() << endl;
}

void increase(Circle* c) {
	int r = c->getRadius();
	c->setRadius(r + 1);
	cout << c->getRadius() << endl;
}

int main() {
	Circle donut;
	//increase(donut);		// Call By Value. 값만 보냄..  // 도넛의 반지름은 그대로 유지.
	increase(&donut);		// Call By Reference

	cout << donut.getRadius() << endl;
	return 0;
}