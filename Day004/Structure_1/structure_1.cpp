#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPEED 200
#define FUEL_STEP 2
#define ACC_STEP 10		// accel
#define BRK_STEP 10		// break

struct Car {
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void showCar(Car &car) {			// 자동차의 현재 상태를 출력하는 메서드
	cout << "소유자ID : " << car.gamerID << endl;
	cout << "현재 연료량 : " << car.fuelGauge << endl;
	cout << "현재 속도 : " << car.curSpeed << endl << endl;
}

void Accel(Car &car) {				// 자동차의 악셀페달을 밟는 행위를 하는 메서드
	if (car.fuelGauge <= 0) {
		cout << "연료가 부족합니다." << endl << endl;
		return;
	}
	else {
		car.fuelGauge -= FUEL_STEP;

		if (car.curSpeed + ACC_STEP > MAX_SPEED)
			car.curSpeed = MAX_SPEED;
		else
			car.curSpeed += ACC_STEP;
	}
}

void Break(Car &car) {				// 자동차의 브레이크페달을 밟는 행위를 하는 메서드
	if (car.curSpeed - BRK_STEP <= 0)
		car.curSpeed = 0;
	else
		car.curSpeed -= BRK_STEP;
}

int main() {
	Car car = { "aaa", 10, 0 };
	showCar(car);

	// 속도증가
	Accel(car); // 연료 - 8, 속도 - 10
	showCar(car);

	/*
	while (true) {
		cout << "동작입력 : ";
		cin >> 
		switch ()
	

	}*/
	return 0;
}