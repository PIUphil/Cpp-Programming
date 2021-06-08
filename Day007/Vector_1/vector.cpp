/*
  vector : 가변 크기 배열
*/

#include <iostream>
#include <vector>
// #include <algorithm> // 모든 알고리즘을 갖다 쓰기
using namespace std;

/*
  push_back(요소) : 마지막에 추가
  at(인덱스) : 추출, 참조
  begin(), end() : 컨테이너의 시작,마지막 위치
  empty() : 벡터가 비어있는지를 bool값으로 리턴 true/false
  erase(iterator it) : it가 가리키는 원소 삭제 (자동으로 벡터 크기조절됨. it는 포인터)
  insert(iterator it, element) : it가 가리키는 곳에 요소(element) 삽입
  size() : 원소(요소)의 개수
*/

int main() {
	vector<int> v;		// 정수벡터 생성

	// 원소 삽입
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	// 원소개수와 용량
	int s = v.size();		// 크기 3
	int c = v.capacity();	// 용량 3 ... 다름;? // 최대크기

	// cout << s << endl << c << endl << endl;

	// 원소 접근
	v.at(2) = 5;			// 1 2 5
	int num = v.at(1);		// 2
	v[0] = 10;				// 10 2 5
	int num2 = v[2];		// 5

	// 벡터의 요소 출력
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}
