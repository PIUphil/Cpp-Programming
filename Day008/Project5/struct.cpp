/*
  구조체(structure type)
  - 사용자정의 자료형
  - 서로 다른 자료를 묶어서 하나의 단위로 처리하는 자료구조
  - 구성 : 멤버변수 or 멤버필드
  - c++ 구조체 구성 : 멤버필드와 멤버메서드로 구성된다. // 접근제한자는 없음
  - 키워드 struct
*/

#include <iostream>
#include <cstring>		// c언어에서의 string.h 파일과 동일함. c++로 넘어오면서 이름이 변경
/*
strlen : 문자열 길이
strcpy : 문자열 복사, 대입연산자(=) 사용하지 못하므로.
strcmp : 문자열 비교, 0(일치), 1, -1
*/

//#include <string>
using namespace std;
#pragma warning(disable:4996)


// 구조체 정의
struct Employee {
	char name[20];		// 20byte, 영문자-19글자, 한글-9글자
	int pay;

	void disp() {
		cout << "직원이름 : " << name << endl;
		cout << "직원급여 : " << pay << endl << endl;
	}
};

int main() {
	// 구조체변수 : 객체변수
	Employee emp[3];
	
	/*Employee emp1;
	Employee emp2 = { "장보고", 20000 };
	Employee emp3 ;*/
	emp[1] = { "장보고", 20000 };

	// 구조체변수를 이용해서 멤버접근 : dirct연산자(.)
	emp[0].pay = 10000;
	//emp.name = "kim";		대입연산자를 사용할 수 없음
	strcpy(emp[0].name, "홍길동");		// strcpy_s - 문자열 크기를 지정해주지 않았을때..(비주얼스튜디오용 -_-)

	cout << "직원이름 = ";
	cin >> emp[2].name;
	cout << "직원급여 = ";
	cin >> emp[2].pay;

	/*for (int i = 0; i < 3; i++) {
		cout << "직원이름 : " << emp[i].name << endl;
		cout << "직원급여 : " << emp[i].pay << endl << endl;
	}*/
	for (int i = 0; i < 3; i++)
		emp[i].disp();

	return 0;
}