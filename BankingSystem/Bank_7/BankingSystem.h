#pragma once
#include <iostream>
#include <string>
#pragma warning(disable:4996)
#include "Account.h"

using namespace std;


class BankingSystem {
	// 객체 포인터 배열 : 동적할당
	Account* accList[100];
	int accNum;// = 0;			// 멤버메서드 초기값으로 줌

public:
	BankingSystem();			// 선언만 하고, 밑에서 작성

	void showMenu() const;		// 메뉴출력
	void makeAccount();			// 계좌개설
	void makeNormalAccount();
	void makeHighAccount();
	void depositMoney();		// 입금처리
	void withdrawMoney();		// 출금처리
	void showAllAccount() const;		// 전체고객 잔액조회

	~BankingSystem();
};