#include <iostream>
using namespace std;

class Circle {
public:
	int radius;

public:
	Circle();
	Circle(int r);
	~Circle();				// 소멸자
	double getArea();
};

Circle::Circle(){
	radius = 1;
	cout << "반지름이 " << radius << "인 원 생성" << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름이 " << radius << "인 원 생성" << endl;
}
Circle::~Circle() {
	cout << "반지름이 " << radius << "인 원 소멸" << endl;
}										// 소멸자는 역순으로 진행
double Circle::getArea() {
	return radius * radius * 3.14;
}

// 전역객체
Circle globalDonut(1000);			// 1 ~12
Circle globalPizza(3000);			// 2 ~11

void f() {
	// 지역객체
	Circle fDonut(100);				// 5 ~8
	Circle fPizza(300);				// 6 ~7

}

int main() {
	// 생성자와 소멸자의 실행순서
	/*Circle donut;
	Circle pizza(30);*/

	// 지역객체 생성
	Circle mainDonut;				// 3 ~10
	Circle mainPizza(30);			// 4 ~9
	f();
	//cout << donut.getArea() << endl;
	//cout << pizza.getArea() << endl;

	return 0;
}
