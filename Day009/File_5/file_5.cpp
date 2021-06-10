#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* first = "D:/C++_Prograimming/source/student.txt";
	const char* second = "C:/Windows/system.ini";

	// step1. + step2.
	fstream fout(first, ios::out | ios::app);		// 출력, 추가
	if (!fout) {
		cout << first << "열기 실패\n";
		return 0;
	}

	fstream fin(second, ios::in);
	if (!fin) {
		cout << second << "열기 실패\n";
		return 0;
	}

	// step3.
	int ch;

	while ((ch = fin.get()) != EOF) {
		fout.put(ch);
	}

	// step4.
	fout.close();
	fin.close();



	return 0;
}