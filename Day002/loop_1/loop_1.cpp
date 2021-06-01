/*
  반복문 : 조건에 의해 특정 문장을 반복해서 처리하는 문
  - 동일하거나 유사한 문장을 반복해서 처리한다.
  - 유사한 문장 : 동일한 행위를 하되, 일정한 규칙을 가지는 문장
  - 종류 : while, do~while, for
  - for : 횟수를 통해서 문장을 제어할 때
	for(초기식;조건식;증감식) {
		반복할 문장;
	}
  - while : 사용자의 행위에 의해 문장을 제어할 때, 무한Loop 중 사용자가 벗어나고자 할 때
	while (조건식) {
		반복할 문장;
	}
  - do~while : 조건이 거짓이라도 딱 한번은 수행되는 문장
	do {
		반복할 문장;
	} while (조건식);
  
*/

// ctrl + shift + '/'  ->  범위 주석처리

#include <iostream>
using namespace std;

int main() {
	/*cout << '#';
	cout << '#';
	cout << '#';
	cout << '#';
	cout << '#';*/

	/*for (int i=1; i<=5; i++) {
		cout << '#';
	}*/

	/*int i = 1;
	while (i<=5) {
		cout << '#';
		i++;
	}*/

	int i = 1;
	do {
		cout << '#';
		i++;
	} while (i<=5);

	return 0;
}