#include <iostream>
using namespace std;

int& refFuncOne(int& ref) {
	/* int& ref = num1; */				// ref�� num1�� ������
	ref++;
	return ref;							
}

int main() {
	int num1 = 1;
	int& num2 = refFuncOne(num1);		// num2�� ref�� ������

	num1++;
	num2++;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

}	// ������ ���� �Ǵٸ� ������ ���� �� �ִ�