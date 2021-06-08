/*
  string 관련 함수
*/

#include <iostream>
#include <string>
using namespace std;

/*
int main() {
	string s1, s2, s3;
	s1.assign("ABCDEFG");			// 할당 - s1에 ABCDEFG를 넣음
	s2.assign(3, 'a');		// (개수, 문자) - 문자를 개수만큼 할당
	s3.assign(s1, 2, 4);	// (문자열, 시작위치, 개수) s1에서 2번째 인덱스부터 4개만 담아라

	cout << s1 << " : " << s2 << " : " << s3 << endl;

	return 0;
}*/

int main() {
	string s1, s2, s3;
	s1.append("ABCDEFG");
	s1.append(3, 'a');			// ABCDEFGaaa
	s2 = "S2";
	s2.append(s1, 2, 4);		// S2CDEF

	/*
	  문자열.clear() : 문자열의 내용을 모두 삭제
	  문자열1.compare(문자열2) : 0(같음), 1(문자열1이 사전에서 뒤), -1	// 문자열1,2를 비교
	  문자열.empty() : 문자열이 비어있는지 true or false
	  문자열.erase(시작위치,개수) : 시작위치에서 개수만큼 지운다
	*/

	s2.empty();		// False(0)

	s1.assign("ABCDEF");
	s2 = "B";
	s3 = "EF";
	
	//  .find : 특정 문자열을 찾고, 그 시작위치를 반환
	int location = s1.find(s2);			// 1
	int location1 = s1.find(s3);		// 4


	// 문자열.replace(시작위치, 개수, 문자열) : 문자열을 대체
	string s = "ABC_DEF";
	s.replace(4, 3, "XYZ");		// ABC_XYZ

	
	// 문자열.insert(시작위치, 문자열) : 시작위치에 문자열을 삽입
	s = "ABCDEF";
	s.insert(3, "__");			// ABC__DEF


	// 문자열.pop_back : 문자열의 가장 뒤에 문자 하나를 뺌
	// 문자열.push_back : 문자열의 뒤에 문자를 추가
	s = "ABCDEFG";
	s.pop_back();				// ABCDEF
	s.push_back('X');			// ABCDEFX


	// 문자열.substr(시작위치, 개수) : 문자열의 일부분 추출
	string a = s.substr(4);			// 4번째부터 모두 추출
	string b = s.substr(1, 3);		// 1번부터 3개만 추출


	// 문자열1.swap(문자열2) : 문자열1과 문자열2를 서로 바꾼다.
	s1 = "ABC";
	s2 = "XYZ";
	s1.swap(s2);


	// 문자열.c_str() : string 문자열을 char*형으로 바꿔서 반환
	s = "ABC";
	int length = strlen(s.c_str());		// 3


	// 문자열.front() : 문자열의 첫번째 문자 반환
	// 문자열.back() : 문자열의 마지막 문자 반환
	s.front();			// A
	s.back();			// C


	return 0;
}

