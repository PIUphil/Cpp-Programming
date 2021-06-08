#include <iostream>
using namespace std;

int main() {
	double pi = 3.14;		// 지역변수

	auto calc = [pi](int r) -> double {return pi * r * r; };
	// 지역변수를 캡쳐해서 double일거라고 생각하지만...컴파일러가 지정하게 해주자 -_-
	
	// return 과 계산할 값을 지정해주면, 내가 타입을 정할 수 있음
	/*double calc2 = [pi](int r) {return pi * r * r; }(3);
	cout << calc2 << endl;*/

	cout << "면적 : " << calc(3);

	return 0;
}