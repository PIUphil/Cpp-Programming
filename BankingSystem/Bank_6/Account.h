// [분리하기] acc선언부

#pragma once
#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
using namespace std;
/*
  클래스 이름 : Account
  핸들러클래스 : AccountManager
*/


// 구조체 - 서로 관련된 자료형을 하나로 묶어서 관리하는 자료구조
class Account {
	int id;					// 계좌번호
	int balance;			// 예금잔고
	// char name[NAME_LEN];	// 고객이름		// 동적할당으로 바꿈
	char* name;				// 고객이름

public:

	Account(int id, int money, char* cusName);	// 생성자 메서드
	Account(const Account& ref);		// 복사 생성자

	int getId() const;
	int getBalance() const;
	void inBalance(int money);
	int outBalance(int money);

	void showAccount() const;

	~Account();
};