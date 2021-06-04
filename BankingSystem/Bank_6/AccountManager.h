// [분리하기] am 선언부 

#pragma once
#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
#include "Account.h"

using namespace std;
/*
  클래스 이름 : AccountManager
  클래스 유형 : Handler 클래스 or Control 클래스
*/


class AccountManager {
	// 객체 포인터 배열 : 동적할당
	Account* accList[100];
	int accNum;// = 0;			// 멤버메서드 초기값으로 줌

public:
	AccountManager();			// 선언만 하고, 밑에서 작성

	void showMenu() const;			// 메뉴출력
	void makeAccount();			// 계좌개설
	void depositMoney();		// 입금처리
	void withdrawMoney();		// 출금처리
	void showAllAccount() const;		// 전체고객 잔액조회

	~AccountManager();
};