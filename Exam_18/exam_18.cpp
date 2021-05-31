/*
  증감연산자 : ++ / --
  - 피 연산자를 1씩 증가 or 감소시킬 때 사용하는 연산자
  - 단항 연산자
  - 전위와 후위연산자의 우선순위에 주의!!
*/

#include <iostream>
using namespace std;

int main() {
	int num1 = 8, num2 = 8;
	int x = 10;
	int res1, res2, y;
	
	res1 = --num1 + 5;
	res2 = num2-- + 5;

	y = x-- + 5 + --x;
	/* 1) x-- + 5   = 15, x는 9가 됨
	   2) 15 + --x  = x는 8이 되고, 15+8 = 23 */

	cout << "res1 : " << res1 << ", num1 = " << num1 << endl;
	cout << "res2 : " << res2 << ", num2 = " << num2 << endl;

	cout << "y : " << y << " , x = " << x << endl;
	
	return 0;
}