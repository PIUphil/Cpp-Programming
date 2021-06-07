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

    string getName() {
        return name;
    }

    void disp() {
        cout << "이름 : " << name << endl;
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

    int getPay() {
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
    void disp() {
        Employee::disp();
        cout << "급여 : " << getPay() << endl << endl;
    }
};