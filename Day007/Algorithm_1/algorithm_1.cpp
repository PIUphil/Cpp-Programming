/*
  STL 알고리즘
  - 템플릿 함수
  - 전역 함수
  - STL 컨테이너 클래스의 멤버 함수는 아니다.
  - iterator와 함께 사용
  - sort(시작위치, 마지막위치)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;

	cout << "5개의 정수를 입력하세요.\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "번째 정수 = ";
		int num;
		cin >> num;
		v.push_back(num);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());

	// 반복자
	// vector<int>::iterator it;
	//for (it = v.begin(); it != v.end(); it++)
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}