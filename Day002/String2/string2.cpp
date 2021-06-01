/*
  c-스트링 방식을 이용하여 암호를 입력받아 정확한 암호가 입력되면
  프로그램이 종료되는 프로그램
  암호 : c++
*/

#include <iostream>
#include <cstring> // c에서 #include <string.h>와 동일
/*
  문자열 관련 함수
  strlen : 문자열의 길이
  strcpy : 문자열 복사
  strcmp : 문자열 비교 , strcmp(문자열1, 문자열2)
			( -1(사전순으로 봐서 뒤에 단어가 뒤에 위치), 0(일치), 1(앞 단어가 뒤에 위치) )
*/

using namespace std;

int main() {
	char password[12];
	
	cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;

	while (true) {

		cout << "암호 = ";
		cin >> password;

		if (strcmp(password, "c++") == 0) {			// strcmp 일치할 때 0을 반환
			cout << "정상적으로 프로그램을 종료합니다." << endl;
			break;
		}
		else {
			cout << "암호가 일치하지 않습니다." << endl;
		}
	}

	return 0;
}