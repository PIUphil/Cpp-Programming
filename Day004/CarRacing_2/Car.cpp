#include <iostream>
//#include <cstring>		// string.h  : strcpy
#include <string>
using namespace std;
#pragma warning(disable:4996)

#include "Car.h"

enum {
	ID_LEN=20, MAX_SPEED=200, FUEL_STEP=2, ACC_STEP=10, BRK_STEP=10
};

Car::Car(string id, int fuel) {
	gamerID = id;
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::init(string id, int fuel) {		// 멤버필드를 초기화하는 메서드
	//strcpy(gamerID, id);
	gamerID = id;
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::showCar() {			// 자동차의 현재 상태를 출력하는 메서드
	cout << "소유자ID : " << gamerID << endl;
	cout << "현재 연료량 : " << fuelGauge << endl;
	cout << "현재 속도 : " << curSpeed << endl << endl;
}

void Car::Accel() {				// 자동차의 악셀페달을 밟는 행위를 하는 메서드
	if (fuelGauge <= 0) {
		cout << "연료가 부족합니다." << endl << endl;
		return;
	}
	else {
		fuelGauge -= FUEL_STEP;

		if (curSpeed + ACC_STEP > MAX_SPEED)
			curSpeed = MAX_SPEED;
		else
			curSpeed += ACC_STEP;
	}
}

void Car::Break() {				// 자동차의 브레이크페달을 밟는 행위를 하는 메서드
	if (curSpeed - BRK_STEP <= 0)
		curSpeed = 0;
	else
		curSpeed -= BRK_STEP;
}