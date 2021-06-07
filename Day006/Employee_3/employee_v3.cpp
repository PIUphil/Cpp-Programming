/*
  상속(Inheritance) : 기반클래스, 파생클래스
  직원(Employee) : 이름
    정규직(Permanent) : 이름, 급여(기본급)
      영업직(Sales) : 이름, 급여(기본급+수당(판매실적*보너스))
    임시직(Temporary) : 이름, 급여(근무시간*시간당급여)
*/

#include <iostream>
#include <string>
using namespace std;

/*
  클래스 이름 : Employee (최상위 클래스)
  클래스 유형 : Entity 클래스
*/

class Employee {
    string name;

public:
    Employee(string name): name(name) {}

    void setName(string name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    virtual void setPay() {}

    // 추상메서드(가상함수) abstract
    virtual int getPay() const {
        return 0;
    }

    void showName() const {
        cout << "이름 : " << name << endl;
    }

    virtual void disp() const {
        //cout << "이름 : " << name << endl;
    }
};

/*
  클래스 이름 : Permanent
  클래스 유형 : Entity 클래스
*/

class Permanent : public Employee {
    int salary;

public:
    Permanent(string name, int pay)
        : Employee(name), salary(pay) {}

    void setPay(int pay) {
        salary = pay;
    }

    int getPay() const {
        return salary;
    }

    /*
      오버로딩 : 동일한 이름을 가진 메서드를 여러 개 생성
                 단, 매개변수의 개수가 다르거나 데이터 타입이 달라야한다.
      오버라이딩 : 재정의. 
                   부모와 자녀가 같은 이름의 메서드를 가질 때,
                   자녀 메서드가 실행된다.
                   멤버필드는 부모꺼가 실행, 메서드는 자식꺼가 실행 (추상메서드)
    */
    void disp() const {
        //Employee::disp();
        showName();
        cout << "급여 : " << getPay() << endl << endl;
    }
};


class Sales : public Employee {
    int salary;
    int salesResult;        // 매출실적
    int bonus;              // 수당

public:
    Sales(string name, int salary, int result, int bonus)
        : Employee(name), salary(salary), salesResult(result), bonus(bonus) {}

    int getPay() const {
        return salary + (salesResult * bonus);
    }

    void disp() const {
        showName();
        cout << "급여 : " << getPay() << endl << endl;
    }
};


class Temporary : public Employee {
    int times;          // 근무시간
    int pay;            // 시간당 급여

public:
    Temporary(string name, int times, int pay)
        : Employee(name), times(times), pay(pay) {}

    int getPay() const {
        return times * pay;
    }

    void disp() const {
        showName();
        cout << "급여 : " << getPay() << endl << endl;
    }
};


/*
  클래스 이름 : EmployeeManager
  클래스 유형 : Hadler or Control 클래스
*/

class EmployeeManager {
    // 객체 동적 배열
    //Permanent* empList[100];		// 100명 직원을 관리
    Employee* empList[100];         // 부모 객체에 자녀객체를 담아서 관리 - 다형성
    int empNum;

public:
    EmployeeManager() : empNum(0) {}

    // 새로운 직원등록을 위한 메서드
    void addEmployee(Employee* emp) {
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

    manager.addEmployee(new Sales("lee", 100, 1000, 2));
    manager.addEmployee(new Sales("park", 100, 3000, 2));
    manager.addEmployee(new Sales("kim", 100, 5000, 2));

    manager.addEmployee(new Temporary("이알바", 42, 80));
    manager.addEmployee(new Temporary("저알바", 60, 80));
    manager.addEmployee(new Temporary("그알바", 100, 80));


    // 급여총합
    manager.showTotalSalary();

    // 직원정보
    manager.showAllSalary();

    return 0;
}
