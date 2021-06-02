#include <iostream>
using namespace std;

int main() {
	cout << "i" << "\t" << "n" << "\t" << "ref" << endl;
	int i = 1;
	int n = 2;
	int& ref = n;		// 참조변수 선언
	
	n = 4;
	ref++;
	cout << i << "\t" << n << "\t" << ref << endl;

	ref = i;
	ref++;
	cout << i << "\t" << n << "\t" << ref << endl;

	int* p = &ref;
	*p = 20;
	cout << i << "\t" << n << "\t" << ref << endl;

	return 0;
}