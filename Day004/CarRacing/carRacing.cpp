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

	void showCar() {			// 자동차의 현재 상태를 출력하는 메서드
		cout << "소유자ID : " << gamerID << endl;
		cout << "현재 연료량 : " << fuelGauge << endl;
		cout << "현재 속도 : " << curSpeed << endl << endl;
	}

	void Accel() {				// 자동차의 악셀페달을 밟는 행위를 하는 메서드
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

	void Break() {				// 자동차의 브레이크페달을 밟는 행위를 하는 메서드
		if (curSpeed - BRK_STEP <= 0)
			curSpeed = 0;
		else
			curSpeed -= BRK_STEP;
	}
};

int main() {
	Car car = { "aaa", 10, 0 };
	car.showCar();

	// 속도증가
	car.Accel(); // 연료 - 8, 속도 - 10
	car.showCar();

	return 0;
}

// 구조체(struct)안에 함수를 담을 수 있다