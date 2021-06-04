#include <iostream>
using namespace std;

class Test {
	int num1;
	static int num2;

public:
	Test(int n): num1(n) {}

	static void Adder(int n) {		
		//num1 += n;			//	static으로 선언된 함수는 static밖에 담지 못한다..
		num2 += n;
	}
};

int Test::num2 = 0;