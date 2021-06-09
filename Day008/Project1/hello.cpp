// 전처리문 : preprocessor
#include <iostream>		// import (<-다른언어들)와 동일한 의미를 지님	// import - 포함, include - 확장
/*
  ios : input output system. 최상위 객체
  istream + ostream = iostream
  stream(스트림) : 시냇물, 통로(데이터, 제어신호)
  c언어 #include <stdio.h>		// .h = header // c++ => #include <stdio>
  - string.h : 문자열과 관련된 함수를 제공 => cstring (c++)
*/

// 전역함수 or 전역변수 or 매크로상수
/*
  #define 상수명 = 값;
  const(=constant) : 상수
  - 상수는 변하지 않는 수, 고정된 수
*/
using namespace std;		// 한 번밖에 못씀;

namespace A {
	void aaa() {}
	void bbb() {}
}

/*
  이름 없는 이름공간
  - namespace { ... }
  - 모든 객체가 static 키워드가 붙어있는 효과를 낸다.
*/

namespace B {
	void aaa() {}
	void bbb() {}
	void ccc() {}
}

// main함수 : 프로그램의 시작과 끝을 나타내는 함수
int main() {		// 리턴타입 함수명(매개변수) { ... }
	/*
	  이름공간(namespace)과 소유연산자(scope연산자, ::) - ~꺼
	*/
	A::aaa();

	// std::cout << "Hello, World!!" << std::endl;
	cout << "Hello, World!!" << endl;

	/*
	printf	=> cout 객체와 <<연산자
	scanf	=> cin 객체와 >>연산자
	std : c++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름공간
	*/


	return 0;		// 시스템을 종료한다는 의미
}


