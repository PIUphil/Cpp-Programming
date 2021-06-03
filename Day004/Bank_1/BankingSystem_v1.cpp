#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)
/*
  strlen : 문자열 길이
  strcpy : 문자열 복사, 문자열은 대입연산자(=)를 사용불가
  strcmp : 문자열 비교, 결과(1, 0:일치, -1)		// 1 - 앞에꺼가 사전순으로 뒤에있음(ㅎ,z) (<-> -1)
		   strcmp(문자열1, 문자열2)
*/
using namespace std;
const int NAME_LEN = 20;	// const - static(정적), final 고정.변경x.
							// #define NAME_LEN = 20

// 전역함수 선언부
void showMenu();			// 메뉴출력
void makeAccount();			// 계좌개설
void depositMoney();		// 입금처리
void withdrawMoney();		// 출금처리
void showAllAccount();		// 전체고객 잔액조회

// 열거형
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};		// DEPOSIT = 2 , WITHDRAW = 3,... 4, 5
// enumerate

// 구조체 - 서로 관련된 자료형을 하나로 묶어서 관리하는 자료구조
struct Account {
	int id;					// 계좌번호
	int balance;			// 예금잔고
	char name[NAME_LEN];	// 고객이름
};

// 전역변수 - 모든 함수에 적용해서 사용 가능한 변수
Account accList[100];		// Account 구조체의 배열
int accIndex = 0;			// Account 배열의 인덱스

int main() {
	int menu;

	while (true) {
		showMenu();
		cout << "메뉴 = ";
		cin >> menu;

		switch (menu) {
		case MAKE:		// 계좌개설
			makeAccount(); break; 
		case DEPOSIT:	//입금처리	
			depositMoney(); break;
		case WITHDRAW:  // 출금처리
			withdrawMoney();  break;
		case INQUIRE:	// 잔액조회
			showAllAccount();  break;
		case EXIT:		// 작업종료종료
			cout << "프로그램을 종료합니다\n\n";
			return 0;
		default:
			cout << "메뉴의 선택이 올바르지 않습니다.\n\n";
		}
	}
	return 0;
}


// 함수 내용 정의하는 영역
void showMenu() {			// 메뉴출력
	cout << "==== Bank Menu ====\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입금처리\n";
	cout << "3. 출금처리\n";
	cout << "4. 잔액조회\n";
	cout << "5. 프로그램 종료\n";
	cout << "===================\n";
}

void makeAccount() {			// 계좌개설
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

	accList[accIndex].id = num;
	accList[accIndex].balance = money;
	// accList[accIndex].name = cusName;  // 문자열은 대입연산자 사용불가
	strcpy(accList[accIndex].name, cusName);
	accIndex++;							// 다음 배열의 위치로 이동하기위해서
	
	cout << "계좌개설이 완료되었습니다.\n\n";
}


void depositMoney() {		// 입금처리
	/* 계좌번호를 입력받아 해당 계좌에 금액을 누적하는 작업 */
	int num;
	int money;

	cout << "== 입금처리 ==\n";
	cout << "계좌번호 = ";
	cin >> num;

	for (int i = 0; i < accIndex; i++) {
		if (accList[i].id == num) {			// 계좌번호가 존재한다면
			cout << "입금금액 = ";
			cin >> money;

			// 해당 계좌에 누적하는 작업
			accList[i].balance += money;

			cout << "입금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}

void withdrawMoney() {		// 출금처리
	/*	계좌번호를 입력받고 해당계좌에 금액을 출력한다.
		단, 해당 계좌의 잔액이 출금금액보다 클 경우 출금하지못하도록 한다. */
	
	int num;
	int money;

	cout << "== 출금처리 ==\n";
	cout << "계좌번호 = ";
	cin >> num;

	for (int i = 0; i < accIndex; i++) {
		if (accList[i].id == num) {			// 계좌가 존재한다면
			cout << "출금금액 = ";
			cin >> money;

			if (accList[i].balance < money) {
				cout << "잔액이 부족합니다.\n\n";
				return;
			}
			
			accList[i].balance -= money;

			cout << "출금처리가 완료되었습니다.\n\n";
			return;
		}
	}
	cout << "일치하는 계좌번호가 존재하지 않습니다.\n\n";
}

void showAllAccount() {		// 전체고객 잔액조회
	cout << "== 전체고객 잔액조회 ==\n";
	cout << "계좌번호  :   고객이름   :   잔 액\n";
	cout << "===================================\n";
	for (int i = 0; i < accIndex; i++) {
		cout << accList[i].id << "\t:\t" << accList[i].name;
		cout << "\t:\t" << accList[i].balance << endl;
	}
	cout << "===================================\n\n";
}