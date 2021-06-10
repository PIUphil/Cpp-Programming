/*
  "exit"이 입력되면 프로그램을 종료하는 프로그램 구현
  get(char* s, int n) : istream 멤버함수, 문자열 단위로 처리

  getline(chr* s, int n, char delim = '\n')
  : get()과 동일하지만 delim에 지정된 구분문자를 스트링에서 제거
*/

#include <iostream>
#include <cstring>		// string.h와 동일
using namespace std;

int main() {
	char word[80];

	cout << "cin.get(char* , int)로 문자열을 읽어오는 작업\n";

	while (true) {
		cout << "종료하려면 exit를 입력하세요. => ";
		cin.get(word, 80);		// 79개의 영문자, 39개의 한글

		if (strcmp(word, "exit") == 0) {
			cout << "프로그램을 종료합니다.\n";
			return 0;
		}
		else {
			// 입력버퍼에 남아있는 '\n'을 제거하는 작업
			// 제거안하면 무한루프에 빠진다...
			cin.ignore(1);
		}
		cout << word << endl;
	}
	return 0;
}