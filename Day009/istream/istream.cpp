/*
  istream 멤버함수 - 문자 입력, get()
*/

#include <iostream>
using namespace std;

int main() {
	int ch;

	// int get()을 이용해서 한 라인의 문자를 읽어오는 작업
	while ((ch = cin.get()) != EOF) {		// 문자 읽어와서 ch에 저장	// EOF => -1
		cout.put(ch);						// 읽어온 문자 출력
		if (ch == '\n') break;
	}

	return 0;
}
// 반환값이 숫자(int)