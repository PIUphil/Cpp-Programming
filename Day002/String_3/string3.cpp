/*
  Falling in love with you를 부른 가수의 이름을 맞추는 프로그램
  string 클래스를 이용하여 구현
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("Falling in love with you");  // Can't Help Falling in Love 
	string elvis("Elvis Presley");
	string singer;

	cout << song + "를 부른 가수는?";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")";

	getline(cin, singer);

	if (singer == elvis)		// 문자열 비교
		cout << "정답" << endl;
	else
		cout << "틀림" << endl;

	cout << "정답은 " << elvis << "입니다." << endl;

	return 0;
}