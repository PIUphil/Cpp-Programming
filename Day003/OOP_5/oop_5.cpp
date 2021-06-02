/*
  배열을 동적 할당 및 반환
  데이터타입 *포인터변수 = new 데이터타입[배열의 크기]
  delete[] 포인터변수;
*/

// 사용자로부터 정수의 개수를 입력받아 배열을 동적으로 할당하고
// 정수를 입력받아 평균을 계산하여 출력하는 프로그램을 구현하시오.

#include <iostream>
using namespace std;

int main() {
	cout << "배열의 크기 = " << endl;
	int count;
	cin >> count;

	if (count == 0) return 0;

	int* p = new int[count];		// 카운트의 크기만큼 동적으로 할당
	if (!p) {						// 예외처리. 할당되지 않았다면.
		cout << "메모리를 할당하지 못했습니다." << endl;
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "번째 수 = ";
		cin >> p[i];
		sum += p[i];
	}

	cout << "평균 = " << sum / count << endl;

	delete[] p;

	return 0;
}