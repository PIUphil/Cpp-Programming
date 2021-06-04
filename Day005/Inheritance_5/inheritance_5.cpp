/*
  상속을 위한 조건
  - 상속으로 클래스의 관계를 구성하기 위해서는 조건이 필요
  - 상속의 기본조건 IS-A 관계의 성립 (~은 …다.)
  - 상속 : 파생클래스는 기반클래스의 모든 멤버를 포함
	전화기 => 갤럭시, 애플, 샤오미 ...
	나무 => 사과나무, 앵두나무, 배나무, 감나무 ...			->  IS-A
*/

#include <iostream>
#include <string>
using namespace std;

class Computer {
	string owner;

public:
	Computer(string name): owner(name) {}

	void calculate() {
		cout << "요청 내용을 계산합니다.\n";
	}
};

// TableNote < NoteBook < Computer

class NoteBook : public Computer {
	int battery;

public:
	NoteBook(string name, int initChag)			// init_Charge
		: Computer(name), battery(initChag) {}

	void Charging() { battery += 5; }
	void UseBattery() { battery -= 1; }
	int getBatteryInfo() {
		return battery;
	}
	void MovindCal() {
		if (getBatteryInfo() < 1) {
			cout << "충전필요\n";
			return;
		}
		cout << "이동하면서 사용\n";
		calculate();
		UseBattery();
	}
};

class TableNote : public NoteBook {
	string penNo;

public:
	TableNote(string name, int initChag, string pen)
		: NoteBook(name, initChag), penNo(pen) {}

	void write(string p) {
		if (getBatteryInfo() < 1) {
			cout << "충전필요\n";
			return;
		}

		if (penNo.compare(p) != 0) {
			cout << "등록된 펜이 아닙니다.\n";
			return;
		}

		cout << "펜을 이용하여 글을 씁니다.\n";
		UseBattery();
	}
};


int main() {

	return 0;
}