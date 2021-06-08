/*
  범위 기반 for문
  for(개별변수:집합변수)		// 배열의 크기가 명확하지 않으면 사용불가
*/

#include <iostream>
using namespace std;

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	//char arr2[] = { 'a', 'b','c','d','e'};

	// for (int i = 0; i < 5; i++)
	//		cout << arr[i] << " ";

	for(auto i: arr)		
		cout << i << " ";
	cout << endl;

	return 0;
}