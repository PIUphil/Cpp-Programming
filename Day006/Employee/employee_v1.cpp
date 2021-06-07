/*
  상속과 다형성 그리고 추상메서드
  회사에서 직원들의 급여를 관리할 목적으로 프로그램 구현
  정규직(Permanent)으로 관리 - 이름과 급여
  새로운 직원등록, 매달 지급되는 직원급여의 총합, 직원정보
*/

#include <iostream>
#include <string>
using namespace std;

class Permanent {
	string name;
	int salary;

public:
	Permanent(string name, int pay)
		: name(name), salary(pay) {}

	// getter or setter
	int getPay() {
		return salary;
	}

	void disp() {
		cout << "이름 : " << name << endl;
		//cout << "급여 : " << salary << endl << endl;
		cout << "급여 : " << getPay() << endl << endl;
	}
};

// 객체 동적 배열
Permanent* empList[100];		// 100명 직원을 관리
int empNum = 0;

// 새로운 직원등록을 위한 메서드
void addEmployee(Permanent* emp) {
	/*string name;
	int pay;
	cout << "직원이름 = ";
	cin >> name;
	cout << "급여 = ";
	cin >> pay;*/

	empList[empNum++] = emp;
	//empList[empNum++] = new Permanent(name, pay);
}

// 지급되는 직원급여의 총합을 위한 메서드
void showTotalSalary() {
	int tot = 0;

	for (int i = 0; i < empNum; i++) {
		tot += empList[i]->getPay();
	}

	cout << "급여의 총합 : " << tot << endl;
}


// 전체 등록된 직원의 정보를 출력하는 메서드
void showAllSalary() {
	for (int i = 0; i < empNum; i++) {
		empList[i]->disp();
	}
}

int main() {

	/*int inwon;

	cout << "등록할 직원 수 = ";
	cin >> inwon;

	for (int i = 0; i < inwon; i++) {
		cout << i << "번째 직원등록" << endl;
		addEmployee();
	}*/

	// 직원등록
	addEmployee(new Permanent("aaa", 1000));
	addEmployee(new Permanent("bbb", 1500));
	addEmployee(new Permanent("ccc", 2000));


	// 급여총합
	showTotalSalary();

	// 직원정보
	showAllSalary();

	return 0;
}

/*entity class - 데이터 관리 위한 클래스
handler class - 직접 처리하거나 행위를 위한 클래스*/