/*
  다섯 개의 정수를 입력받아 배열에 저장한 후
  그 합과 평균을 계산하여 출력하는 프로그램을 구현하시오.
*/

#include <iostream>
using namespace std;

/*
  step1. 배열로 받아서 처리하는 방법
  step2. 주소를 저장하는 변수 - 포인터변수. 배열처럼 사용가능
*/

//int adder(int data[]) {
//	int sum = 0;
//	for (int i = 0; i < 5; i++) {
//		sum += data[i];
//	}
//	return sum;
//}

int adder(int* data) {			// data = &arr[0]
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += *data++;
	}
	return sum;
}


float average(int s, int z) {
	return s/(float)z;
}


int main() {
	int arr[5], sum=0;		// 누적변수는 초기화를 시켜야한다.
	float avg;	

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 정수 = ";
		cin >> arr[i];
	}

	sum = adder(arr);
	avg = average(sum, sizeof(arr)/sizeof(arr[0]));
	//avg = sum / 5.0f;

	cout << "sum = " << sum << endl;
	cout << "average = " << avg << endl;

	return 0;
}