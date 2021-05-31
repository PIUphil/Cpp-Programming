#include<iostream>
using namespace std;

int main() {
	/*
	  cin 객체, console input 객체, 입력받을 때(입력 스트림)
	  cin >> 저장할 변수;
	  추출연산자(>>) : 사용자로부터 입력받은 값을 추출해서 우측의 변수에 저장한다.
	*/

	// 선언문 : 변수나 상수의 자료형을 선언할 때 사용하는 문장
	int age;

	cout << "나이를 입력해 주세요 : ";
	cin >> age;

	cout << "당신이 입력한 나이는 " << age << "살 입니다." << endl;
	// endl : end of line 줄의 끝을 의미. 즉, 개행(\n) 
	return 0;
}