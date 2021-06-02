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
	//Circle cArray[3];	// 기본생성자에 의해 배열 생성
	Circle cArray[3] = {Circle(), Circle(5), Circle(10)};	// 배열을 초기화할 때, 생성자가 들어가야 함

	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적 = " << cArray[i].getArea() << endl;
	}
	return 0;
}