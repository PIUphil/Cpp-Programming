/*
  STL(Standard Template Library) : 일반화 프로그래밍
  - 일반화 프로그래밍은 데이터를 중시하는 객체지향 프로그래밍과는 달리
	프로그램의 알고리즘에 중점을 둔 기법
  - C++ 표준 템플릿 라이브러리 구성요소
	반복자(iterator)
	컨테이너(container) : 같은 타입의 여러 객체를 저장
						  클래스 템플릿		// 일반적으로 사용하기 좋게 모아놓은 클래스들의 집합?
	알고리즘(Algorithm) : 함수들

  - 컨테이너 : 순차(sequence) - 순서대로 데이터를 저장하기 위한 컨테이너 (ex.리스트)
			   연관(associative), 어댑터(adapter)	
  - 순차 컨테이너 : vector, list, deque(queue의 확장판, stack+queue의 장점들 모음)
  - 연관 컨테이너 : set, map(파이썬의 dict와 비슷)
  - 어댑터 컨테이너 : stack, queue
*/

#include <iostream>
#include <vector>
using namespace std;

//template <typename T>
//class Vector { };

int main() {
	// 벡터객체 생성 및 초기화
	vector<int> vc = { 10, 20, 30 };				// 동적배열(크기가 지정되어있지않음)
	
	cout << "현재 벡터의 크기 : " << vc.size() << endl;		// size() : 크기

	// 벡터 요소 추가
	vc.push_back(40);										// push_back() : 뒤에 추가
	
	cout << "벡터의 네번째 요소 : " << vc[3] << endl;
	cout << "현재 벡터의 크기 : " << vc.size() << endl;

	copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, ", "));	// copy(시작값, 마지막값, 출력반복자

	return 0;
}
