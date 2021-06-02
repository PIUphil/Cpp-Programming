#include <iostream>
using namespace std;
#define PI 3.14

class Circle {
public:
	int radius;

public:
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() {
	radius = 1;		// 멤버필드를 초기화
	cout << "반지름 = " << radius << "원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;		// 멤버필드를 초기화
	cout << "반지름 = " << radius << "원 생성" << endl;
}

double Circle::getArea() {
	return radius * radius * PI;
}

/*
  반지름을 입력받아 원의 면적을 계산하여 출력하는 프로그램
  단, 입력받은 반지름이 0이면 프로그램을 종료하시오.
*/


int main() {

	int r; 
	// Circle c;

	while (true) {
		cout << "반지름 = ";
		cin >> r;

		if (r == 0) {
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}

		Circle c(r);
		cout << "원의 면적 = " << c.getArea() << endl;	
	}
	return 0;
}