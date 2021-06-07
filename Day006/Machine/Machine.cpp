/*
  커피자동판매기 프로그램을 구현하시오.
  Entity 클래스와 Handler 클래스로 구분하여 기술하시오.
  주어진 조건과 입출력 형식에 맞게 구현하시오.

  <입력 및 출력형식>
  == Coffee Machine ==
  1. 에스프레소
  2. 아메리카노
  3. 설탕커피
  4. 프림커피
  5. 재료충전
  6. 잔량확인
  ====================
  선택 = 


  <처리조건>
  1. 커피자동판매기 클래스 CoffeeMachine은 멤버필드로 커피, 물, 설탕, 프림, 컵을 가지고 있다.
  2. 각 재료는 기본적으로 3개씩 담겨있다.
  3. 재료충전시 각 재료의 충전값을 사용자가 직접 입력하도록 구현한다.
  4. 에스프레소는 커피1과 물1을 소모한다.
  5. 아메리카노는 커피1과 물2를 소모한다.
  6. 설탕커피는 커피1과 물2와 설탕1을 소모한다.
  7. 프림커피는 커피1과 물2와 프림1을 소모한다.
  8. 모든 커피는 컵1을 소모한다.
*/

#include <iostream>
using namespace std;


class Container {
	int size;			// 현재 저장량. 최대 10개 저장가능

public:
	Container() {
		size = 10;
	}

	void fill();		// 재료를 자동으로 채우는 메서드
	void consume();		// 1소모
	int getSize();		// 현재 용량 리턴
};

void Container::fill() {
	size = 10;
}

void Container::consume() {
	size--;
}

int Container::getSize() {
	return size;
}


/*
  커피자판기를 표현하는 클래스
*/

class CoffeeMachine {
	Container box[5];		// 커피[0], 설탕[1], 프림[2], 컵[3], 물[4]

public:
	void fill();				// 5개의 통에 모두 10으로 충전
	void selectEspresso();		// 에스프레소를 선택(커피1, 물1, 컵1)
	void selectAmericano();		// 아메리카노를 선택(커피1, 물2, 컵1)
	void selectSugarCoffee();	// 설탕커피를 선택(커피1, 물2, 컵1, 설탕1)
	void selectPreamCoffee();	// 프림커피를 선택(커피1, 물2, 컵1, 프림1)
	//void fill();			// 충전 선택
	void show();			// 잔량확인 선택

	void run();			// 머신 작동
};


void CoffeeMachine::fill() {
	for(int i = 0; i < 5; i++)
		box[i].fill();

	show();
}

void CoffeeMachine::selectEspresso() {
	// 커피[0], 설탕[1], 프림[2], 컵[3], 물[4] 
	for (int i = 0; i < 5; i++) {
		if (box[i].getSize() == 0) {
			cout << "재료가 부족합니다." << endl <<endl;
			run();
		}
	}
	
	box[0].consume();
	box[3].consume();
	box[4].consume();
	cout << "에스프레소가 나왔습니다.\n" << endl;
}

void CoffeeMachine::selectAmericano() {
	// 커피[0], 설탕[1], 프림[2], 컵[3], 물[4] 
	for (int i = 0; i < 5; i++) {
		if (box[i].getSize() == 0) {
			cout << "재료가 부족합니다." << endl << endl;
			run();
		}
	}

	box[0].consume();
	box[3].consume();
	box[4].consume(); box[4].consume();
	cout << "아메리카노가 나왔습니다.\n" << endl;
}

void CoffeeMachine::selectSugarCoffee() {
	// 커피[0], 설탕[1], 프림[2], 컵[3], 물[4] 
	for (int i = 0; i < 5; i++) {
		if (box[i].getSize() == 0) {
			cout << "재료가 부족합니다." << endl << endl;
			run();
		}
	}

	box[0].consume();
	box[1].consume();
	box[3].consume();
	box[4].consume(); box[4].consume();
	cout << "설탕커피가 나왔습니다.\n" << endl;
}

void CoffeeMachine::selectPreamCoffee() {
	// 커피[0], 설탕[1], 프림[2], 컵[3], 물[4] 
	for (int i = 0; i < 5; i++) {
		if (box[i].getSize() == 0) {
			cout << "재료가 부족합니다." << endl << endl;
			run();
		}
	}

	box[0].consume();
	box[2].consume();
	box[3].consume();
	box[4].consume(); box[4].consume();
	cout << "프림커피가 나왔습니다.\n" << endl;
}

void CoffeeMachine::show() {
	cout << "커피 잔량 : " << box[0].getSize() << endl;
	cout << "설탕 잔량 : " << box[1].getSize() << endl;
	cout << "프림 잔량 : " << box[2].getSize() << endl;
	cout << "컵   잔량 : " << box[3].getSize() << endl;
	cout << "물   잔량 : " << box[4].getSize() << endl;
}


enum { Espresso = 1, Americano, SugarCoffee, PreamCoffee, Fill, Show };

void CoffeeMachine::run() {
	int menu;
	bool check = true;

	while (check) {
		cout << "== Coffee Machine ==\n";
		cout << "1. 에스프레소\n";
		cout << "2. 아메리카노\n";
		cout << "3. 설탕커피\n";
		cout << "4. 프림커피\n";
		cout << "5. 재료충전\n";
		cout << "6. 잔량확인\n";
		cout << "====================\n";
		cout << "선택 = ";
		cin >> menu;

		switch (menu) {
		case Espresso: selectEspresso(); break;
		case Americano: selectAmericano(); break;
		case SugarCoffee: selectSugarCoffee(); break;
		case PreamCoffee: selectPreamCoffee(); break;
		case Fill: fill(); break;
		case Show: show(); break;
		default: break;
		}
	}
}


int main() {
	CoffeeMachine* coffee = new CoffeeMachine();
	coffee->run();

	delete coffee;
	return 0;
}

// Handler Class = CoffeeMachine