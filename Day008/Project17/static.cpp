#include <iostream>
using namespace std;

//static int x = 0;					// 전역변수

void aaa() {
	static int x = 0;	//지역변수		static을 붙이면 다시 호출하더라도 초기화가 더이상 되지 않는다.(처음 한번만 초기화 함)
	//x = 0;			//전역변수
	x++;
	cout << x << endl;
}

int main() {

	for (int i = 0; i < 10; i++)
		aaa();

	return 0;
}