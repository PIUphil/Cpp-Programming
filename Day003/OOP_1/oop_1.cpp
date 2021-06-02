// OOP 객체지향프로그래밍 (Object-Oriented Programming)
/* 
  객체 포인터 : 객체에 대한 포인터 변수를 선언하여 사용하는 것
  포인터 변수 : 메모리의 주소를 저장하는 변수
  자료형 : 기본자료형, 사용자정의자료형(배열명, 구조체형, 클래스, 포인터...)
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle();
	Circle(int radius);
	double getArea();
};

Circle::Circle() {
	radius = 1;
}

Circle::Circle(int radius) {
	this->radius = radius;			// -> 내꺼..  포인트연산자  ( java에선 '.'을 사용)
}

double Circle::getArea() {
	return radius * radius * 3.14;
}

int main() {
	Circle donut;		// 객체 생성
	Circle pizza(30);
	Circle* p;			// 객체 포인터변수 선언

	p = &donut;			// 도넛의 주소를 담음 (p 초기화)

	cout << "donut 객체 면적 = " << donut.getArea() << endl;
	cout << "p 포인터 객체 면적 = " << p->getArea() << endl;	// 포인트연산자
	cout << "p 포인터 객체 면적 = " << (*p).getArea() << endl;

	p = &pizza;
	cout << "p 포인터 객체 면적 = " << p->getArea() << endl;
	cout << "p 포인터 객체 면적 = " << (*p).getArea() << endl;

	return 0;
}