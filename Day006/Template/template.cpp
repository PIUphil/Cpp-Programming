/*
  템플릿(Template) == 일반화
  - 함수의 오버로딩의 단점을 보완하기 위해서 생성
*/

#include <iostream>
using namespace std;

// 다양한 자료형에서도 작동되도록 일반화해줌
template<typename T>

// int 대신 T사용
//int max(int data[], int size) {
T max(T data[], int size) {
	//int max = data[0];
	T max = data[0];
	for (int i = 0; i < size; i++) {
		if (max < data[i]) max = data[i];
	}

	return max;
}

//double max(double data[], int size) {
//	double max = data[0];
//	for (int i = 0; i < size; i++) {
//		if (max < data[i]) max = data[i];
//	}
//
//	return max;
//}


int main() {
	int arr[] = { 1, 3, 2, 7, 9, 6, 4 };
	double d[] = { 1.2, 3.7, 2.5, 4.6, 9.3, 10.1, 7.9 };

	int size = sizeof(arr) / sizeof(arr[0]);
	int big = max(arr, size);

	cout << "큰 값 = " << big << endl;

	double bigger = max(d, 7);	
	cout << "큰 값 = " << bigger << endl;

	return 0;
}