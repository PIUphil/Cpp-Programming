#include <iostream>
using namespace std;

#include "Circle.h"

int main() {
	Circle c;
	// c.radius = 5;		 // radius가 private로 되어있어서 직접접근불가
	c.setRadius(5);
	cout << "반지름 = " << c.getRadius() << endl;
	cout << "넓이 = " << c.getArea() << endl;

	return 0;
}