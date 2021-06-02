/*
  객체 배열 : 동일한 클래스에 의해 생성된 여러 개의 객체를 묶는 것
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea();
};

double Circle::getArea() {
	return radius * radius * 3.14;
}


int main() {
	Circle cArray[3];		// Circle a; Circle b; Circle c; // 객체 배열 3개

	// 객체배열의 요소를 이용해서 접근
	cArray[0].setRadius(10);
	cArray[1].setRadius(20);
	cArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적 = " << cArray[i].getArea() << endl;
	}

	Circle* p;			// 포인터 변수 생성
	p = cArray;			// 배열명은 배열의 시작주소와 같다. (= &cArray[0])
	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적 = " << p->getArea() << endl;
		p++;
	}

	return 0;
}