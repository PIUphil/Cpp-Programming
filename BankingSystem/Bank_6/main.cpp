// [분리하기] main

#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
#include "Account.h"
#include "AccountManager.h"

using namespace std;

// 열거형
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };		// DEPOSIT = 2 , WITHDRAW = 3,... 4, 5

/*
  컨트롤 클래스인 AccountManager 중심으로 main 변경
*/

int main() {
	int menu;

	AccountManager manager;

	while (true) {
		manager.showMenu();
		cout << "메뉴 = ";
		cin >> menu;

		switch (menu) {
		case MAKE:		// 계좌개설
			manager.makeAccount(); break;
		case DEPOSIT:	//입금처리	
			manager.depositMoney(); break;
		case WITHDRAW:  // 출금처리
			manager.withdrawMoney();  break;
		case INQUIRE:	// 잔액조회
			manager.showAllAccount();  break;
		case EXIT:		// 작업종료종료
			// 동적할당 반환
			/*for (int i = 0; i < accNum; i++)		// AccountManager에서 소멸자로 해둠
				delete manager.accList[i];*/

			cout << "프로그램을 종료합니다\n\n";
			return 0;
		default:
			cout << "메뉴의 선택이 올바르지 않습니다.\n\n";
		}
	}
	return 0;
}