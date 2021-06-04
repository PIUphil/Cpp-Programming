/*
  객체지향적인 프로그래밍 : 클래스, 캡슐화(정보은닉), 상속, 다형성, 추상화...

  상속(Inheritance) : 부모의 꺼를 자식이 물려받는 것
  - 클래스와 클래스 간의 상속을 말한다.
  - 부모클래스 or 상위클래스 or 기반클래스
  - 자녀클래스 or 하위클래스 or 파생클래스

  클래스 기능에 따라
  - Entity Class or Data Class : 단순히 데이터만 담는 역할
  - Control Class or Handler Class : 실제 데이터를 가지고 처리하는 용도로 사용되는 클래스
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


// Entity Class : 단순히 데이터의 흐름만 알고 있는 클래스
class Permanent {
private:
	//char name[100];
	string name;
	int salary;

public:
	/*Permanent(char* name, int money)
		: salary(money) {
		strcpy(this->name, name);
	}*/
	Permanent(string name, int money)
		: salary(money) {
		this->name = name;
	}

	int getPay() const {
		return salary;
	}

	void showSalary() const {
		cout << "이름 : " << name << endl;
		cout << "급여 : " << salary << endl << endl;
	}
};


// Handler Class : 기능들 위주로 구성된 클래스
class EmployeeManager {
private:
	// 객체 포인터 배열 - 동적할당
	// 클래스명 포인터변수 = new 클래스명(매개변수);
	Permanent* empList[100];
	int empNum;

public:
	EmployeeManager(): empNum(0) {}

	// 직원 등록하는 메서드
	void AddEmployee(Permanent* p) {
		empList[empNum++] = p;
	}

	// 매달 지급되는 직원의 급여의 총합을 출력하는 메서드
	void showTotalSalary() const {				// const는 멤버에만 붙일 수 있음..
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->getPay();

		cout << "전체 직원의 급여 = " << sum << endl << endl;
	}

	// 모든 직원의 정보를 출력하는 메서드
	void showAllSalary() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->showSalary();
	}

	~EmployeeManager() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};



int main() {
	
	EmployeeManager handler;

	// 직원등록
	Permanent emp1("aaa", 10000);
	handler.AddEmployee(new Permanent(emp1));		// 동적할당 값이 와야함
	handler.AddEmployee(new Permanent("bbb", 15000));
	handler.AddEmployee(new Permanent("ccc", 20000));
	
	// 직원 급여의 총 합
	handler.showTotalSalary();

	// 등록된 직원의 정보
	handler.showAllSalary();

	return 0;
}