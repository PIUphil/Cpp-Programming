/*
  객체와 객체 배열의 동적 생성 및 반환
  클래스이름 *포인터변수 = new 클래스이름;
  클래스이름 *포인터변수 = new 클래스이름(생성자 매개변수);
  delete 포인터변수;
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
};

// 반지름을 입력받아 Circle 객체를 동적으로 할당하여 면적을 출력한다.
// 단, 반지름으로 음수가 입력되면 프로그램을 종료한다.

int main() {
	int r;

	while (true) {
		cout << "반지름 = ";
		cin >> r;
		if (r < 0) {
			cout << "프로그램 종료" << endl;
			return 0;
		}

		Circle* p = new Circle(r);

		cout << "면적 = " << p->getArea() << endl;

		delete p;		// 할당된 것 반환
	}
	return 0;
}

/*
int main() {
	Circle* p, * q;
	p = new Circle();
	q = new Circle(30);

	cout << "p면적 = " << p->getArea() << endl;
	cout << "q면적 = " << q->getArea() << endl;

	delete p, q;

	return 0;
}*/