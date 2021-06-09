/*
  배열의 크기를 입력받아 동적으로 할당한 후
  데이터를 입력받아 출력하는 프로그램
*/

#include <iostream>
using namespace std;



int main() {
	int arr_size;
	
	cout << "배열의 크기 = ";
	cin >> arr_size;

	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++) {
		cout << i + 1 << "번째 데이터 = ";
		cin >> list[i];					// 포인터도 배열처럼 사용가능
	}

	cout << "배열의 요소 : " << endl;
	for (int i = 0; i < arr_size; i++) 
		cout << list[i] << " ";

	cout << endl;

	delete []list;

	return 0;
}