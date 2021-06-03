#include <iostream>
using namespace std;

int& refFuncOne(int& ref) {
	/* int& ref = num1; */				// ref가 num1을 참조함
	ref++;
	return ref;							
}

int main() {
	int num1 = 1;
	int& num2 = refFuncOne(num1);		// num2가 ref를 참조함

	num1++;
	num2++;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

}	// 참조를 통해 또다른 참조를 만들어낼 수 있다