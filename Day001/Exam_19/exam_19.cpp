/*
  비교연산자 : 두 피연산자의 대소관계를 비교하는 연산자
  - 연산의 결과는 true or false로 출력
  - 종류 : ==(같다), !=(같지 않다), >, >=, <, <=

  논리연산자 : 논리값(true or false)을 이용해서 연산을 수행하는 연산자
  - 종류 : &&(and), ||(or) - 이항  /  !(not, 논리부정) - 단항
  - 연산의 결과는 true or false
  - 하나 이상의 비교연산자를 묶어서 계산을 수행할 때 사용
  - && : 모두, 이고. 두 조건식 모두 참일 때 결과가 참
  - || : 이거나, 또는. 어느거 하나라도 참이면 결과가 참
  - ! : 참이면 거짓, 거짓이면 참
*/

#include <iostream>
using namespace std;
/*
int main() {
	int num1 = 3, num2 = 7;

	cout << "!= 연산자 " << (num1 != num2) << endl; // true(1)
	cout << ">= 연산자 " << (num1 >= num2) << endl;	// false(0)

	return 0;
}*/

int main() {
	int num1 = 3, num2 = -7;
	bool res1, res2;

	res1 = (num1 > 0) && (num1 < 5);	// true && true == true(1)
	res2 = (num2 < 0) || (num2 > 10);	// true || false == true(1)

	cout << "&& = " << res1 << endl;
	cout << "|| = " << res2 << endl;
	cout << "! = " << !res2 << endl;	// false
	cout << "! = " << !5 << endl;		// false. 0이 아니면 다 참으로 간주
	return 0;
}