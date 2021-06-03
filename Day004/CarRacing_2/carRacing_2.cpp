#include <iostream>
//#include <cstring>		// string.h  : strcpy
#include <string>
using namespace std;
#pragma warning(disable:4996)

#include "Car.h"


int main() {
	Car car = { "aaa", 10 };
	//car.init("aaa", 10);
	car.showCar();

	// 속도증가
	car.Accel(); // 연료 - 8, 속도 - 10
	car.showCar();

	return 0;
}