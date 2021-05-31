/*
  함수(Function)
  - 여러 개의 명령어를 하나의 이름으로 담아서 관리하는 객체
  - 특별한 목적을 수행하기 위해 독립적으로 설계된 코드의 집합
  - 캡슐화
  - 이유 : 반복적인 프로그래밍을 효율적으로 수행
  - 선언
	 반환 자료형 함수명(매개변수들) {
		// 함수의 내용정의부
	 }
  - 호출을 통해서 동작한다.
  - 호출방법
     Call By Name : 이름에 의한 호출
	 Call By Value : (값에 의한 호출)함수에 매개변수를 담아서 호출
	 Call By Reference : (주소에 의한 호출)함수에 매개변수의 주소를 담아서 호출
*/

#include <iostream>
using namespace std;

// 함수 선언부  // 함수가 뒤에있으면 앞에서 선언을 해줘야 함. 선언 안하면 없는줄 앎...
void aaa();
void bbb(int*, int*);  // (int x, int y)로 써도 됨


int main(void) {
	// 선언문
	int x, y;

	// 입력문
	x = 10; y = 20;

	// 처리문
	//aaa();			// Call By Name
	//bbb(x, y);		// Call By Value
	bbb(&x, &y);		// Call By Reference

	// 출력문
	cout << "x = " << x << " , y = " << y << endl;

	return 0;  // int 반환. 시스템 종료.
}


void aaa() {
	cout << "aaa 함수 호출" << endl;
	//return;
}

void bbb(int* x, int* y) {	// x=10, y=20 // 같은 int라도 생략하면 안된다. 독립된 개체
	int tmp;					
	tmp = *x;
	*x = *y;
	*y = tmp;				// 이 함수 안에서만 x,y가 서로 바뀜 (지역변수)

	cout << "x = " << *x << " , y = " << *y << endl;
}


/*
int *x = &x
int *y = &y
          main
*/