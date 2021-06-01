/*
  함수(Function)
  - 관련된 명령어를 독립적인 단위로 묶어서 처리하는 형태
  - 특별한 목적의 작업을 수행하기 위해 설계된 코드의 집합
  - 캡슐화
  - 함수의 선언
	반환자료형 함수명(매개변수) {
		함수의 내용 정의부;  // 함수의 몸체
		return;
	}

  - 함수의 호출방법 : Call By Name, Call By Value, Call By Reference
  - 반환자료형 == 결과형리턴값 : 기본자료형과 사용자정의 자료형
	int, long, float, double, bool, short ...
	배열명, 구조체명, 클래스명, 포인터형 ...
*/


#include <iostream>
using namespace std;

// 리턴값x, 매개변수x
void aaa() {
	cout << "aaa함수 호출" << endl;
}

// 리턴값x, 매개변수o
void bbb(int x) {
	cout >> endl;
}


// Day1 - 16장 참조..