/*
  List : 이중 연결 리스트, 배열의 동적 자료형으로 이해
*/

#include <iostream>
#include <list>			// 클래스 사용하려면 include 해줘야함
using namespace std;

int main() {
	int arr[10];
	list<int> li = {1, 2, 2, 3, 4, 3, 5, 5};
	/*
	  swap() : 두 요소의 위치를 서로 바꿈
	  reverse() : 역순
	  sort() : 정렬
	  unique() : 고윳값
	  merge() : 병합
	*/

	li.sort();		// 1, 2, 2, 3, 3, 4, 5, 5
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, ", "));
	cout << endl<<endl;
	
	li.unique();	// 1, 2, 3, 4, 5
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, ", "));
	cout << endl << endl;

	return 0;
}