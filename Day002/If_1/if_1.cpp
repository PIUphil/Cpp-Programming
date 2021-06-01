/*
  제어문 : 조건문(비교판단문 or 선택문), 반복문, 기타제어문
  - 기타제어문 : break, continue
  - 조건문 : 조건식에 의해 처리할 문장을 선택하는 제어문
  - 단순 if문 : 조건식이 참일 때 처리할 문장을 제어하는 문
  - if ~ else문 : 조건식이 참일 때와 거짓일 때 문장을 제어하는 문
  - 다중 if문 : 여러 개의 조건식에 의해 처리할 문장을 제어하는 문
  - switch ~ case ~ break 문 : 다중 if문 확장, 처리속도가 빠르다.
*/

# include <iostream>
using namespace std;


// 하나의 숫자를 입력받아 짝수인지 판정하는 프로그램
/*int main() {
	// 선언문
	int num;
	
	// 입력문
	cout << "num = ";
	cin >> num;

	// 처리문
	if (num % 2 == 0)
		cout << "입력받은 숫자 " << num << "은 짝수입니다." << endl;
	else
		cout << "입력받은 숫자 " << num << "은 홀수입니다." << endl;
	
	return 0;
}*/


// 두 개의 숫자를 입력받아 큰 수를 출력하는 프로그램
/*int main() {
	int su1, su2;

	cout << "두 개의 정수를 입력하세요. : ";
	cin >> su1 >> su2;

	if (su1 > su2)
		cout << su1 << " 과 " << su2 << " 중 큰 수는 " << su1 << endl;
	else
		cout << su1 << " 과 " << su2 << " 중 큰 수는 " << su2 << endl;

	return 0;
}*/


// 세 개의 숫자를 입력받아 큰 순서대로 출력하는 프로그램
int main() {
	int first, second, third, tmp;

	cout << "세 개의 정수 입력 : ";
	cin >> first >> second >> third;

	// 가장 큰 수가 first가 되는 경우

	if (second > first && second > third) {
		tmp = first;
		first = second;
		second = tmp;
	}
	else if (third > first && third > second) {
		tmp = first;
		first = third;
		third = tmp;
	}
	
	if (second < third) {
		tmp = second;
		second = third;
		third = tmp;
	}

	cout << first << " > " << second << " > " << third << endl;

	return 0;
}