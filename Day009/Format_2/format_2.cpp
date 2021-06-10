/*
  포맷 함수
  - int width(int minWidth) : 출력되는 필드의 최소너비
  - char fill(char cFill) : cFill 문자로 빈 칸을 채운다
  - int precision(int np) : 출력 숫자의 유효숫자 자릿수를 np로 설정 
	정수와 소수점 이하의 수의 자리를 모두 포함하고 소수점을 제외  
*/

#include <iostream>
using namespace std;

int main() {
	cout.width(10);					// 출력되는 값의 너비가 10칸으로 지정
	cout << "Hello" << endl;		// 우측맞춤		// Hello + '\0' 이 오른쪽 6칸 차지하고, 왼쪽4칸 비어있음
	cout.width(5);
	cout << 12 << endl;				// 우측맞춤


	cout.fill('^');					// 빈칸을 채움
	cout.width(10);						
	cout << "Hello" << endl;		
	cout.width(5);
	cout << 12 << endl;				

	cout.precision(5);				// 유효자릿수 5칸
	cout << 11.0 / 3.0 << endl;		// 3.6667	// 소수점 무시하고 5개. 마지막은 반올림

	return 0;
}