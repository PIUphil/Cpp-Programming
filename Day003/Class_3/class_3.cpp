/*
  사각형(Rectangle) 객체를 구현하시오.
  멤버로는 너비(width)와 높이(height)를 필드로 가지고,
  사각형의 면적을 계산하여 되돌려주는 메서드 getArea()를 구현할 것.
  단, 클래스의 선언부와 구현부로 분리하여 구현할 것.
*/

#include <iostream>
using namespace std;

class Rectangle {				// 클래스 선언부

public:
	int width, height;			// 멤버필드

public:
	int getArea();				// 멤버메서드
};

int Rectangle::getArea() {		// 클래스 구현부
	return width * height;
}


int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;

	// int area = rect.getArea();
	cout << "사각형 면적 = " << rect.getArea() << endl;

	return 0;
}