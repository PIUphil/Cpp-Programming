/*
  10진수, 8진수, 16진수로 출력되도록 프로그램을 구현
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << showbase;

	// title
	cout << setw(8) << "Number";		//setw - set wide 너비
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;

	// number
	for (int i = 0; i < 50; i += 5) {
		cout << setw(8) << setfill('.') << dec << i;		//	setfill - 빈칸을 ~로 채움
		cout << setw(10) << setfill(' ') << oct << i;
		cout << setw(10) << setfill(' ') << hex << i << endl;
	}

	// number	// 왼쪽정렬
	for (int i = 0; i < 50; i += 5) {
		cout << setw(8) << left << setfill('.') << dec << i;		//	setfill - 빈칸을 ~로 채움
		cout << setw(10) << left << setfill(' ') << oct << i;
		cout << setw(10) << left << setfill(' ') << hex << i << endl;
	}

	return 0;
}