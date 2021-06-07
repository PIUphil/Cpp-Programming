/*
  계좌종류 : 보통예금(NormalAccount), 신용예금(HighAccount)
  처리조건
  1. 보통예금은 기존의 예금과 동일하나, 입금처리가 진행될 시 입금액의 3%를 이자로 추가입금한다.
  2. 신용예금은 고객의 신용에 따라 입금처리가 진행될 시
	 A등급은 7%를 이자로 추가입금, B등급은 5%, C등급은 3%를 지급한다
  3. 계좌를 개설하는 과정에는 입금되는 금액에 이자를 계산하지 않는다.
  4. 계좌를 개설한 후 입금과정을 거칠 때에만 이자를 추가한다.
  5. 이자를 계산하는 과정에서 발생하는 소수점 이하의 금액은 무시한다.
  6. 기타 조건은 입출력 형식에 맞게 구현한다.

  <입력 및 출력형식>
  ===== Bank Menu =====
  1. 계좌개설
  2. 입금처리
  3. 출금처리 
  4. 전체고객 잔액조회
  5. 프로그램 종료
  =====================
  메뉴 =

  ===== 계좌개설 =====
  1. 보통예금 계좌개설
  2. 신용예금 계좌개설
  ====================
  선택 = 1

  계좌번호 = 
  고객이름 = 
  예금금액 = 
  예금이자율(%) =

  ===== 계좌개설 =====
  1. 보통예금 계좌개설
  2. 신용예금 계좌개설
  ====================
  선택 = 2

  계좌번호 =
  고객이름 =
  예금금액 =
  예금이자율(%) =
  신용등급(1toA, 2toB, 3toC) = 

*/

#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
#include "BankingSystem.h"

using namespace std;

// 열거형
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };		// DEPOSIT = 2 , WITHDRAW = 3,... 4, 5

/*
  컨트롤 클래스인 AccountManager 중심으로 main 변경 // BankingSystem
*/

int main() {
	int menu;

	//AccountManager manager;
	BankingSystem manager;

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
			cout << "프로그램을 종료합니다\n\n";
			return 0;
		default:
			cout << "메뉴의 선택이 올바르지 않습니다.\n\n";
		}
	}
	return 0;
}