/*
  Entity Class와 Handler Class 분리하는 작업
  - Handler Class or Control Class
	: 프로그램 전체의 기능을 담당하는 클래스
	  기능적 성격이 강한 클래스
  - Entity Class
	: 데이터적 성격이 강하다.
	  프로그램의 기능을 파악하지 못한다.
	  단순히 데이터를 담아 관리하는 역할만 수행한다.
*/

#include <iostream>
#include <cstring>		// string.h 
#pragma warning(disable:4996)

using namespace std;
const int NAME_LEN = 20;

// 열거형
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };		// DEPOSIT = 2 , WITHDRAW = 3,... 4, 5

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


// Account 클래스 구현부
Account::Account(int id, int money, char* cusName)
	: id(id), balance(money) {
	// 동적할당 - 기억공간 최소화
	name = new char[strlen(cusName) + 1];
	strcpy(name, cusName);
}

Account::Account(const Account& ref)						// const
	: id(ref.id), balance(ref.balance) {
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}

int Account::getId() const { return id; }
int Account::getBalance() const { return balance; }
void Account::inBalance(int money) {
	balance += money;
}
int Account::outBalance(int money) {
	if (balance < money)
		return 0;			// 잔액이 부족할 경우
	else
		balance -= money;
	return money;
}

void Account::showAccount() const {
	cout << id << "\t:\t" << name << "\t:\t" << balance << endl;
}

Account::~Account() {
	delete[] name;
}


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

// AccountManager 클래스 구현부
AccountManager::AccountManager(): accNum(0) {}
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

/*
[분리하기]
main / acc선언부 / am 선언부 / acc구현부 / am구현부
*/