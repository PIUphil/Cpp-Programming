#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle() {
	radius = 1;
}

Circle::Circle(int r) {
	radius = r;
}

double Circle::getArea() {
	return radius * radius * 3.14;
}

void Circle::setRadius(int r) {
	radius = r;
}

int Circle::getRadius() {
	return radius;
}