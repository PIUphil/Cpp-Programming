#include <iostream>
using namespace std;

class Point;

class PointOP {
	int opcnt;

public:
	PointOP() : opcnt(0) {}

	Point PointAdd(const Point&, const Point&);		
	Point PointSub(const Point&, const Point&);				
	~PointOP() {
		cout << "Operation times : " << opcnt << endl;
	}
};

class Point {
	int x;
	int y;

public:
	Point(const int &xpos, const int &ypos)
		: x(xpos), y(ypos) {}

	friend Point PointOP::PointAdd(const Point&, const Point&); // 전역함수인데 자기껏처럼 사용가능.. -> 멤버필드에 접근가능
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void showPointPos(const Point&);
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void showPointPos(const Point& pos) {
	cout << "x = " << pos.x << endl;
	cout << "y = " << pos.y << endl;
}


int main() {
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	showPointPos(op.PointAdd(pos1, pos2));
	showPointPos(op.PointSub(pos2, pos1));

	return 0;
}