/*
  상속과 다형성 그리고 추상메서드
  회사에서 직원들의 급여를 관리할 목적으로 프로그램 구현
  정규직(Permanent)으로 관리 - 이름과 급여
  새로운 직원등록, 매달 지급되는 직원급여의 총합, 직원정보
*/

#include <iostream>
#include <string>
using namespace std;

/*
  클래스 이름 : Permanent
  클래스 유형 : Entity 클래스		// java - bin, model
*/

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


/*
  클래스 이름 : EmployeeManager
  클래스 유형 : Hadler or Control 클래스
*/

class EmployeeManager {
	// 객체 동적 배열
	Permanent* empList[100];		// 100명 직원을 관리
	int empNum;

public:
	EmployeeManager() : empNum(0) {}

	// 새로운 직원등록을 위한 메서드
	void addEmployee(Permanent* emp) {
		empList[empNum++] = emp;
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

	~EmployeeManager() {
		// 동적할당 받은 공간을 반환하는 역할
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};


int main() {

	EmployeeManager manager;

	// 직원등록
	manager.addEmployee(new Permanent("aaa", 1000));
	manager.addEmployee(new Permanent("bbb", 1500));
	manager.addEmployee(new Permanent("ccc", 2000));


	// 급여총합
	manager.showTotalSalary();

	// 직원정보
	manager.showAllSalary();

	return 0;
}