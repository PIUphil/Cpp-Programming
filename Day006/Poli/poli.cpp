/*
  다음과 같은 프로그램이 동작되도록 구현하시오.
  <입력 및 출력형식>
  도형 (1.원, 2.사각형, 3.도형보기, 4.종료)
  선택 = 1
  x = 5
  y = 5
  r = 5

  선택 = 1
  x = 3 
  y = 4
  r = 7

  선택 = 2
  x = 10
  y = 10
  h = 7
  w = 9

  <처리조건>
  1. 사용자가 원하는 도형을 입력받도록 구현한다.
  2. 도형은 총 10개만 저장하도록 객체배열을 생성한다.
	 이 때, 원 4개, 사각형 6개 이거나, 원 7개, 사각형 3개 등등...
	 무조건 도형은 10개만 입력받도록 구현한다.
  3. 도형보기를 선택하면 이제껏 입력한 도형의 정보가 출력되도록 구현한다.
  4. 언제든 프로그램이 종료되도록 구현한다.
  5. 원(Circle)은 반지름을 멤버로 구현한다.
  6. 사각형(Rect)은 너비(width)와 높이(height)를 멤버로 구현한다.

*/

#include <iostream>
using namespace std;

/* 평면 위의 한 점을 객체화하는 클래스*/
class Point {
	int x;
	int y;

public:
	//Point(int x=0, int y=0): x(x), y(y) {}
	Point() {
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
	}

	virtual void disp() const {}

	void showPosition() const {
		cout << "점(x, y) = (" << x << ", " << y << ")" << endl;
	}
};


class Circle : public Point {
	int r;

public:
	Circle() {
		// Point(); 가 생략되어있다.
		cout << "r = ";
		cin >> r;
	}

	void disp() const {
		showPosition();
		cout << "반지름(r) = " << r << endl;
	}
};


class Rect : public Point {
	int h;
	int w;	

public:
	Rect() {
		cout << "h = ";
		cin >> h;
		cout << "w = ";
		cin >> w;
	}

	void disp() const {
		showPosition();
		cout << "높이(h) = " << h << ", 너비(w) = " << w << endl;
	}
};


Point* p[10];		// 객체동적배열
int index = 0;


int main() {
	/*Point ap;
	ap.showPosition();*/

	/*Circle c;
	c.disp();

	Circle c2;
	c2.disp();

	Rect r;
	r.disp();*/

	int ch;

	for (int i = 0; i < 10; i++) {
		cout << "도형 (1.원, 2.사각형, 3.도형보기, 4.종료)\n";
		cout << "선택 = ";
		cin >> ch;
	
		if (ch == 1) {
			p[i] = new Circle();
		}

		else if (ch == 2) {
			p[i] = new Rect();
		}

		else if (ch == 3) {
			for (int a = 0; a<i; a++)
				p[a]->disp();
			i--;
		}

		else if (ch == 4) {
			cout << "프로그램을 종료합니다." << endl;
			for (int j = 0; j < index; j++)
				delete p[j];

			return 0;
		}

		else {
			cout << "잘못선택되었습니다." << endl;
			i--;
		}
	}
	return 0;
}