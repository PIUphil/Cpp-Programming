/*교통카드 잔액을 관리하는 프로그램
교통카드 초기 금액은 20000원이다.

운임은 고정 요금이 아닌 거리 규칙에 따라 측정 및 공제된다.

기본 요금은 40km에 720원, 추가요금은 41km부터 8km당 80원
프로그램은 각 이동거리를 입력하여 카드의 최종 잔액을 출력한다.

최소이동거리는 4km, 최대 이동거리는 178km이다.

입력값이 위에 주어진 범위를 벗어나면 현재 잔액을 출력하고,
프로그램을 종료한다.*/

#include <iostream>
using namespace std;


class Trfcard {
	static int money;

public:
	Trfcard();
	int getMoney();
	void setMoney(int fare);
};

Trfcard::Trfcard() { money = 20000; }
int Trfcard::getMoney() { return money; }
void Trfcard::setMoney(int fare) { money -= fare; }

int Trfcard::money = 0;


int fareCalc() {
	int distance;
	cout << "이동할 거리(4~178) = ";
	cin >> distance;

	if (distance < 4 || distance >178)
		return 0;

	if(distance <= 40)
		return 720;
	else
		return 720 + ((distance - 40) / 8) * 80;
}


int main() {
	Trfcard card;

	while (true) {
		if (card.getMoney() < 720) {
			cout << "잔액이 부족합니다." << endl;
			return 0;
		}

		int c = fareCalc();

		if (c == 0) {
			cout << "카드 잔여 금액은 " << card.getMoney() << "원 입니다." << endl;
			return 0;
		}
		else {
			card.setMoney(c);
			if (card.getMoney() < 0) {
				cout << "잔액이 부족하여 더이상 갈 수 없습니다." << endl;
				return 0;
			}
			cout << "카드 잔여 금액은 " << card.getMoney() << "원 입니다." << endl << endl;
		}
	}
	return 0;
}