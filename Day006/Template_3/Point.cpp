/*
  평면 위의 한 점을 객체화하는 클래스 Point를 일반화하는 템플릿으로 구현하시오.
*/


#include <iostream>
using namespace std;

template <typename T> // 여러 개를 쓸 땐 추가 나열  ', typename Q>'
class Point {
	T x, y;

public:
	Point(T x, T y);
	void setX(T x);
	void setY(T y);
	T getX();
	T getY();
};

template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <typename T>
void Point<T>::setX(T x) {
	this->x = x;
}

template <typename T>
void Point<T>::setY(T y) {
	this->y = y;
}

template <typename T>
T Point<T>::getX() {
	return x;
}

template <typename T>
T Point<T>::getY() {
	return y;
}


int main() {
	Point<double> pos1(1.5, 2.4);

	cout << "x = " << pos1.getX() << endl;
	cout << "y = " << pos1.getY() << endl;
	return 0;
}