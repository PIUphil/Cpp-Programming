/*
  조건문 : 주어진 조건식에 의해 처리되는 문
  - 조건식은 반드시 그 결과가 참 또는 거짓으로 판정되어야 한다.
  - if문, switch~case, 조건연산자(삼항연산자)

  삼항연산자 : 항을 세 개 가지고 있는 연산자
  - if~else문의 모체가 된다.
  - 형식
	조건항? 항1: 항2;	
	변수 = 조건항? 항1: 항2;

	조건항(조건식)이 참이면 항1, 그렇지 않으면 항2가 실행된다.
*/

#include <iostream>
using namespace std;

int bigger(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}

// 세 개의 정수를 입력받아 큰 수를 찾아 출력하는 프로그램
int main() {
	int num1, num2, num3, max;

	cout << "num1 = ";
	cin >> num1;
	cout << "num2 = ";
	cin >> num2;
	cout << "num3 = ";
	cin >> num3;

	/*max = num1 > num2 ? num1 : num2;
	max = num3 > max ? num3 : max;*/
	max = bigger(num1, num2);
	max = bigger(num3, max);

	cout << "max = " << max << endl;

	return 0;
}

