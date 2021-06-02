#pragma once
class Circle {
	int radius;			// private

public:
	Circle();
	Circle(int r);
	double getArea();
	void setRadius(int r);
	int getRadius();
};