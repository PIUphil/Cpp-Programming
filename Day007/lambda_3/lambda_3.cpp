#include <iostream>
using namespace std;

int main() {
	int sum = 0;		// 지역변수

	[&sum](int x, int y) {sum = x + y; }(2, 3);		// 주소를 가져와서 합칠 수 있다..

	cout << "sum = " << sum << endl;

	return 0;
}