/*
  ostream 멤버 함수 : put, write
*/

#include <iostream>
using namespace std;

int main() {
	// "Hello!"를 출력하고 다음 줄로 넘기는 작업
	cout.put('H');
	cout.put('e');
	cout.put('l');
	cout.put('l');
	cout.put('o');
	cout.put(33);	// ASCII 코드값(!)	// cout.put('!');
	cout.put('\n');

	// 'C++'를 출력
	cout.put('C').put('+').put('+').put(' ');
	cout << endl;

	char str[] = "I love programming";
	cout.write(str, 6);				// str에서 6글자만 출력(공백포함)

	return 0;
}