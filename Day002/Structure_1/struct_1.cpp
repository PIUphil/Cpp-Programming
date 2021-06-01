/*
  구조체(structure) -> 클래스 (확장)
  - 서로 다른 타입의 자료형을 하나로 묶어서 관리하는 자료구조
  - 구조체의 멤버 or 멤버 변수
  - 선언 : struct 구조체형명{
			int a;
			float b;
			char c;
		    };			// 끝에 세미콜론(;)이 붙음
*/

#include <iostream>
using namespace std;

struct Book {
	char title[30];
	char author[30];
	int price;
};

int main() {
	// 구조체변수(객체)
	// struct Book book;
	struct Book web_book = { "C++ Programming", "홍길동", 28000 };		//구조체 선언+초기화

	cout << "책 제목 : " << web_book.title << endl;
	cout << "저자명  : " << web_book.author << endl;
	cout << "책 가격 : " << web_book.price << endl;

	return 0;
}