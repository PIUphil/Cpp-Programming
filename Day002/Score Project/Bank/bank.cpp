/*
  계좌관리 프로그램
  <처리조건>
  1. Account 라는 구조체를 선언하여 처리한다.
  2. 구조체 멤버는 고객이름, 계좌번호, 예금금액을 담아서 처리한다.
  3. 계좌개설, 입금처리, 출금처리, 고객계좌정보 출력을 수행하는 함수를 구현한다.
  4. 둘 이상의 고객을 관리하기 위해 구조체 배열을 사용한다.
  5. 사용자가 원하는 작업을 수행할 수 있도록 구현한다.
  6. 기타 조건은 입출력 형식에 맞게 동작되도록 구현한다.

  <입력 및 출력형식>
  == 계좌관리 프로그램 ==
  1. 계좌개설
  2. 입금처리
  3. 출금처리
  4. 전체고객 잔액조회
  5. 프로그램 종료
  ========================
  메뉴 =

  == 계좌개설 ==
  계좌번호 =
  고객이름 =
  예금금액 =
  ===============
  계좌개설이 완료되었습니다.

  == 입금처리 ==
  계좌번호 =
  입금금액 =
  ===============
  입금처리가 완료되었습니다.

  == 출금처리 ==
  계좌번호 =
  출금금액 =
  ===============
  출금처리가 완료되었습니다.

  == 전체고객 잔액조회 ==
  계좌번호  고객이름  예금잔액
  ----------------------------
  xxx       xxx        xxx

  ============================

  
*/

#include <iostream>
#include <string>
using namespace std;


struct Account {	
	int num, money;
	string name;
};

Account account[5];			// 고객 최대 5명

int choice, in_num, in_money;
int i = 0;					// 계좌개설번호

void Make(), Deposit(), Withdraw(), Show();		// 개설, 입금, 출금, 조회


int main() {
	while (true) {
		cout << "== 계좌관리 프로그램 ==" << endl
		<< "1. 계좌개설" << endl
		<< "2. 입금처리" << endl
		<< "3. 출금처리" << endl
		<< "4. 전체고객 잔액조회" << endl
		<< "5. 프로그램 종료" << endl
		<< "========================" << endl;

		cout << "메뉴 = ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1: Make();	break;					// "1. 계좌개설"
			case 2: Deposit(); break;				// "2. 입금처리"
			case 3: Withdraw();	break;				// "3. 출금처리"
			case 4: Show(); break;		 			// "4. 전체고객 잔액조회"
			case 5: {								// "5. 프로그램 종료"
				cout << "== 프로그램을 종료합니다. ==" << endl;
				return 0;
			} break;
			default: cout << "잘못된 선택입니다." << endl << endl;	// "기타. 선택오류"
		}
	}
	return 0;
}

// 계좌개설 함수
void Make() {
	if (i > 5) {
		cout << "인원초과. 더이상 계좌를 만들 수 없습니다." << endl << endl;
		return;
	}

	cout << "== 계좌개설 ==" << endl;
	cout << "계좌번호 = (숫자)";
	cin >> account[i].num;

	for (int k = 0; k < i; k++) {
		if (account[k].num == account[i].num) {
			cout << "이미 존재하는 계좌입니다. 다른 번호를 입력해주세요." << endl << endl;
			return;
		}
	}

	cout << "고객이름 = ";
	cin >> account[i].name;
	cout << "예금금액 = ";
	cin >> account[i].money;
	cout << "==============" << endl;
	cout << "계좌개설이 완료되었습니다." << endl <<endl;
	i++;
}

// 입금 함수
void Deposit() {
	cout << "== 입금처리 ==" << endl;
	cout << "계좌번호 =";
	cin >> in_num;
	
	int chk = 0;
	for (int k = 0; k < i; k++) {
		if (account[k].num == in_num)
			chk = 1;
	}
	if (chk==0) {
		cout << "입력하신 계좌가 존재하지 않습니다." << endl << endl;
		return;
	}

	cout << "입금금액 =";
	cin >> in_money;

	for (int k = 0; k < i; k++) {
		if (account[k].num == in_num) {
			account[k].money += in_money;
		}
	}
	
	cout << "==============" << endl;
	cout << "입금처리가 완료되었습니다." << endl << endl;
}

// 출금 함수
void Withdraw() {
	cout << " == 출금처리 ==" << endl;
	cout << "계좌번호 =";
	cin >> in_num;

	int chk = 0;
	for (int k = 0; k < i; k++) {
		if (account[k].num == in_num)
			chk = 1;
	}
	if (chk == 0) {
		cout << "입력하신 계좌가 존재하지 않습니다." << endl << endl;
		return;
	}

	cout << "출금금액 =";
	cin >> in_money;

	for (int k = 0; k < i; k++) {
		if (account[k].num == in_num) {
			if (account[k].money < in_money) {
				cout << "잔액이 부족합니다."<< endl;
				cout << "==============" << endl << endl;
			}
			else {
				account[k].money -= in_money;
				cout << "==============" << endl;
				cout << "출금처리가 완료되었습니다." << endl << endl;
			}
		}
	}
}

// 전체 계좌 조회 함수
void Show() {								
	cout << "=========== 전체고객 잔액조회 ===========" << endl;
	cout << "계좌번호\t고객이름\t예금잔액" << endl;
	cout << "-----------------------------------------" << endl;
	for (int j = 0; j < i; j++) {
		cout << account[j].num << "\t\t" << account[j].name << "\t\t" << account[j].money << endl;
	}
	cout << "=========================================" << endl << endl;
}