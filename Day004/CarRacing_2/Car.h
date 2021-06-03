#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car {
	//char gamerID[ID_LEN];
	string gamerID;
	int fuelGauge;
	int curSpeed;

public:
	Car(string id, int fuel);
	void init(string id, int fuel); // 멤버필드를 초기화하는 메서드
	void showCar();				// 자동차의 현재 상태를 출력하는 메서드
	void Accel();				// 자동차의 악셀페달을 밟는 행위를 하는 메서드
	void Break();				// 자동차의 브레이크페달을 밟는 행위를 하는 메서드
};