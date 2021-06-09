#include <iostream>
#include <string>
using namespace std;

/*
  static : 정적, 공유
		   클래스의 모든 객체들이 '공유'하는 값
		   static 개체는 static 안에만 담을 수 있다		
*/

class JBank {
	//char name[30];
	string name;
	int money;
	static double rate;

public:
	JBank(string name, int money, double r)
		: name(name), money(money)/*, rate(r)*/ {
		rate = r;					// static이 아니므로 콜론초기화를 할 수 없다;
	}

	void disp() {
		cout << name << " : " << money << " : " << rate << endl;
	}
};

double JBank::rate = 0.0;

int main() {
	JBank aaa("aaa", 1000, 0.5);		// 초기
	aaa.disp();
	cout << endl;

	JBank bbb("bbb", 1000, 0.3);		// 중기
	aaa.disp();
	bbb.disp();
	cout << endl;

	JBank ccc("ccc", 1000, 0.7);
	aaa.disp();
	bbb.disp();
	ccc.disp();	
}