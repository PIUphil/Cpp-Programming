/*
  C++ 문자열
  - C-스트링 : C언어에서 문자열을 표현하는 방식
	배열(array) : 동질의 자료형을 하나의 이름으로 묶어서 관리하는 자료구조
	'K', 'O', 'R', 'E', 'A'
  - string 클래스 : C++에서 문자열을 처리하는 방식, 권장

*/

#include <iostream>
#include <string> // #include <string.h>  <- C언어용  // 문자열을 처리하는 함수를 갖고있는 클래스객체
// strlen 문자열의 길이 // strcmp 두개의 문자열 비교 // strcpy 문자열 복사
using namespace std;

int main() {
	//char a, b, c, d, e;
	//// 배열
	//char arr[5] = {'K', 'O', 'R', 'E', 'A'};
	//char arr[6] = "KOREA";	// null string '\0' 문자열의 끝을 의미 - 마지막에 포함됨
	//							// 큰 따옴표로 문자열을 담을 때는 하나 더 크게 잡아야함

	//char name[12];  // 배열 // 영문자 - 11글자, 한글 - 5글자  
	string names;	// string 자료형(클래스객체)
	
	cout << "이름 = ";
	// getline() - 줄 단위로 읽어옴(엔터 기준)
	// cin >> name;	// 공백을 허용하지 않음 
	// cin.getline(name, 12, '\n'); // 변수명(받을 장소), 최대 몇글자, 종결자(생략가능) // 공백을 허용

	// cin >> names;
	getline(cin, names);  // 콘솔, 받을 장소  // getline 스트링객체 

	cout << "당신의 이름은 " << names << "입니다.\n";

	return 0;
}