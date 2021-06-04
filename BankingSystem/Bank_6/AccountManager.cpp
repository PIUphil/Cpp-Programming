// [분리하기] am구현부


#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
#include "AccountManager.h"
using namespace std;

const int NAME_LEN = 20;


// AccountManager 클래스 구현부
AccountManager::AccountManager() : accNum(0) {}

AccountManager::~AccountManager() {
	for (int i = 0; i < accNum; i++)
		delete accList[i];				// 동적할당 반환
}


// 함수 내용 정의하는 영역
void AccountManager::showMenu() const {			// 메뉴출력
	cout << "==== Bank Menu ====\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입금처리\n";
	cout << "3. 출금처리\n";
	cout << "4. 잔액조회\n";
	cout << "5. 프로그램 종료\n";
	cout << "===================\n";
}

void AccountManager::makeAccount() {			// 계좌개설
	/* 계좌번호, 고객이름, 예금금액 */
	int num;					// 계좌번호
	int money;					// 예금금액
	char cusName[NAME_LEN];		// 고객이름

	cout << "== 계좌개설 ==\n";
	cout << "계좌번호 = ";
	cin >> num;
	cout << "고객이름 = ";
	cin >> cusName;
	cout << "예금금액 = ";
	cin >> money;

	accList[accNum++] = new Account(num, money, cusName);

	cout << "계좌개설이 완료되었습니다.\n\n";
}


void AccountManager::depositMoney() {		// 입금처리
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
			accList[i]->inBalance(money);

			cout << "입금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}

void AccountManager::withdrawMoney() {		// 출금처리
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

			if (accList[i]->outBalance(money) == 0) {
				cout << "잔액이 부족합니다.\n";
			}

			cout << "출금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}

void AccountManager::showAllAccount() const {		// 전체고객 잔액조회
	cout << "== 전체고객 잔액조회 ==\n";
	cout << "계좌번호  :   고객이름   :   잔 액\n";
	cout << "===================================\n";
	for (int i = 0; i < accNum; i++) {
		accList[i]->showAccount();
	}
	cout << "===================================\n\n";
}