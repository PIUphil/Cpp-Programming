/*
  원의 개수를 입력받아 Circle 배열을 동적으로 생성한다.
  반지름 값을 입력받아 Circle 배열에 저장하고,
  면적이 100이상 200이하인 원의 개수를 출력하는 프로그램을 작성하시오.
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

int main() {
	cout << "생성할 원의 개수 = ";
	int n;
	cin >> n;
	if (n == 0) return 0;

	Circle* p = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "반지름 = ";
		int radius;		// radius
		cin >> radius;
		p[i].setRadius(radius);
	}

	if (!p) {
		cout << "메모리를 할당하지 못했습니다." << endl;
		return 0;
	}

	int count = 0;
	Circle* q = p;
	
	for (int i = 0; i < n; i++) {
		//cout << "면적 = " << p[i].getArea() << endl;
		cout << "면적 = " << q->getArea() << endl;
		if (q->getArea() >= 100 && q->getArea() <= 200)
			count++;
		q++;
	}

	cout << " 원의 개수 = " << count << endl;

	delete[] p;		// 할당된 것 반환
	delete q;
	
	return 0;
}



	

