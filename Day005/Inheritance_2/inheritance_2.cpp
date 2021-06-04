/*
  친구 : 이름
  중학교 : 이름, 연락처
  고등학교 : 이름, 연락처, 취미
  대학교 : 이름, 연락처, 학과
  사회 : 이름, 연락처, 직장, 직급
*/

#include <iostream>
#include <string>
using namespace std;

class AAA {
public:
	int x;
	AAA(int x) : x(x) {}
};

class BBB : public AAA {		// AAA 를 상속받음
public:
	int y;
	BBB(int x, int y)
		: AAA(x), y(y) {}		// 자식이 부모 생성자를 초기화해줘야함
};

class CCC  : public BBB {
public:
	int z;
	CCC(int x, int y, int z)
		: BBB(x, y), z(z) {}
};

int main() {
	/*AAA ap;
	ap.x = 1;

	BBB bp;
	bp.y = 2;*/
	
	/*CCC cp;
	cp.z = 3;

	cp.x = 1;
	cp.y = 2;*/

	CCC cp();

	return 0;
}














/*
class Middle {
	string name;
	string phone;
};

class High : public Middle {		// Middle을 상속받으면 name, phone을 또 안써줘도됨
	// string name;
	// string phone;
	string hobby;
};

class Univ : public Middle {
	// string name;
	// string phone;
	string major;
};

class Soc : public Middle {
	// string name;
	// string phone;
	string company;
	string position;
};*/
