/*
  A회사의 직원 급여관리 프로그램
  고용인 : Employee
  정규직 : Permanent - 직원이름, 급여(기본급)
  영업직 : Sales - 직원이름, 급여(기본급 + 판매수당 * 보너스)
  임시직 : Temporary - 직원이름, 급여(시급 * 근무시간)
*/

#include <iostream>
#include <string>
using namespace std;


class Employee {			// 최상위클래스 
	string name;

public:
	Employee(string name) : name(name) {}

	virtual int getPay() {			// 자식에게만 있는거.. (형식적으로만 들고있음.. 리턴해줄건 없음;)
		return 0;			// 똑같은거 있으면 자식꺼가 실행된다?!
	}						// =>> 추상화(abstract)

	virtual void show() {}

	void showName() {
		cout << "이름 : " << name << endl;
	}
};

/*
   클래스 이름 : Permanent
   클래스 유형 : Entity 클래스
*/
class Permanent : public Employee {
	// string name;
	int salary;

public:
	Permanent(string name, int pay)
		: Employee(name), salary(pay) {}		// 부모생성자를 호출, 초기화

	int getPay() { 
		return salary; 
	}

	void show() {
		// cout << "이름 : " << name << endl;
		//Employee::show();
		showName();
		cout << "급여 : " << getPay() << endl << endl;
	}
};

class Sales {
	string name;
	int salary;
	int salesResult;		// 판매실적
	int bonus;				// 실적수당

};

class Temporary {
	string name;
	int times;				// 근무시간
	int pay;				// 시간당 급여
};




/*
  클래스 이름 : EmployeeManager
  클래스 유형 : Handler 클래스
*/
class EmployeeManager {
	//객체 동적 배열
	Employee *empList[100];
	int empNum;

public:
	EmployeeManager() : empNum(0) {}

	// 직원등록을 수행하는 메서드
	void addEmployee(Employee* p) {
		empList[empNum++] = p;
	}

	 // 직원급여의 총합을 출력하는 메서드
	void showTotalSalary() {
		int total = 0;
		for (int i = 0; i < empNum; i++) 
			total += empList[i]->getPay();

		cout << "급여총합 : " << total << endl;
	}

	// 모든 직원의 정보를 출력하는 메서드
	void showAllSalary() {
		for (int i = 0; i < empNum; i++) {
			// empList[i]->showName();
			empList[i]->show();
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
