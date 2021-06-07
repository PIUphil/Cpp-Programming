#include <iostream>
#include <string>
using namespace std;

#include "Account.h"
#include "NormalAccount.h"
#include "HighAccount.h"
#include "BankingSystem.h"

BankingSystem::BankingSystem()
	: accNum(0) {}

void BankingSystem::showMenu() const {		// 메뉴출력
	cout << "===== Bank Menu =====\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입금처리\n";
	cout << "3. 출금처리\n";
	cout << "4. 전체고객 잔액조회\n";
	cout << "5. 프로그램 종료\n";
	cout << "====================\n";
}

void BankingSystem::makeAccount() {			// 계좌개설
	cout << "===== 계좌개설 =====\n";
	cout << "1. 보통예금 계좌개설\n";
	cout << "2. 신용예금 계좌개설\n";
	cout << "====================\n";
	cout << "선택 = ";
	int ch;
	cin >> ch;

	if (ch == 1) {
		makeNormalAccount();
	}
	else if (ch == 2) {
		makeHighAccount();
	}
	else {
		cout << "선택이 올바르지 않습니다.\n\n";
	}
}

void BankingSystem::makeNormalAccount() {
	string name;
	int id;
	int money;
	int rate;

	cout << "== 보통예금 계좌개설 ==\n";
	cout << "계좌번호 = ";
	cin >> id;
	cout << "고객이름 = ";
	cin >> name;
	cout << "예금금액 = ";
	cin >> money;
	cout << "예금이자율(%) = ";
	cin >> rate;

	// 부모 객체에 자식 객체를 담아서 관리 - 다형성적인 표현
	accList[accNum++] = new NormalAccount(name, id, money, rate);
	cout << "보통예금 계좌개설이 완료되었습니다.\n\n";
}


void BankingSystem::makeHighAccount() {
	string name;
	int id;
	int money;
	int rate;
	int special;

	cout << "== 보통예금 계좌개설 ==\n";
	cout << "계좌번호 = ";
	cin >> id;
	cout << "고객이름 = ";
	cin >> name;
	cout << "예금금액 = ";
	cin >> money;
	cout << "예금이자율(%) = ";
	cin >> rate;
	cout << "신용등급(1toA, 2toB, 3toC) = ";
	cin >> special;

	// 부모 객체에 자식 객체를 담아서 관리 - 다형성적인 표현
	switch (special) {
	case 1:
		accList[accNum++] = new HighAccount(name, id, money, rate, 7);
		break;
	case 2:
		accList[accNum++] = new HighAccount(name, id, money, rate, 5);
		break;
	case 3:
		accList[accNum++] = new HighAccount(name, id, money, rate, 3);
		break;
	default:
		break;
	}

	cout << "신용예금 계좌개설이 완료되었습니다.\n\n";
}


void BankingSystem::depositMoney() {		// 입금처리
	/* 계좌번호를 입력받아 해당 계좌에 금액을 누적하는 작업 */
	int num;
	int money;

	cout << "== 입금처리 ==\n";
	cout << "계좌번호 = ";
	cin >> num;

	for (int i = 0; i < accNum; i++) {
		if (accList[i]->getId() == num) {			// 계좌번호가 존재한다면
			cout << "입금금액 = ";
			cin >> money;

			// 해당 계좌에 누적하는 작업
			accList[i]->input(money);

			cout << "입금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}


void BankingSystem::withdrawMoney() {		// 출금처리
	/*	계좌번호를 입력받고 해당계좌에 금액을 출력한다.
		단, 해당 계좌의 잔액이 출금금액보다 클 경우 출금하지못하도록 한다. */

	int num;
	int money;

	cout << "== 출금처리 ==\n";
	cout << "계좌번호 = ";
	cin >> num;

	for (int i = 0; i < accNum; i++) {
		if (accList[i]->getId() == num) {			// 계좌가 존재한다면
			cout << "출금금액 = ";
			cin >> money;

			if (accList[i]->outMoney(money) == 0) {
				cout << "잔액이 부족합니다.\n";
			}

			cout << "출금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}


void BankingSystem::showAllAccount() const {	// 전체고객 잔액조회
	cout << "== 전체고객 잔액조회 ==\n";
	cout << "계좌번호  :   고객이름   :   잔 액\n";
	cout << "===================================\n";
	for (int i = 0; i < accNum; i++) {
		accList[i]->showAllAccount();
	}
	cout << "===================================\n\n";
}

BankingSystem::~BankingSystem() {
	for (int i = 0; i < accNum; i++)
		delete accList[i];
}