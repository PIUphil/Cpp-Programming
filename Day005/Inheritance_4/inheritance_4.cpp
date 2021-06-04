/*
  접근제한자(접근지정자)
  - public : 모두 허용
  - protected : 상속에서 허용
  - private
*/

#include <iostream>
using namespace std;

class Base {
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	void showData() {
		cout << num1 << " : " << num2 << " : " << num3 << endl;
	}
};

class Derived : public Base {
public:
	void show() {
		// cout << num1;	// private - 접근불가
		cout << num2;
		cout << num3;
	}
};

// private < protected < public
class Derived2 : protected Base {		// public(protected보다 큰 것)이 protected가 되어, num3도 접근 못하게 됨
public:									// 거의다 public만 사용함..
	void show() {
		// cout << num1;	// private - 접근불가
		cout << num2;
		cout << num3;
	}
};

int main() {
	Base obj;

	//cout << obj.num1;		// private - 접근불가
	//cout << obj.num2;		// protected - 접근불가	
	cout << obj.num3;

	Derived obj2;

	//cout << obj2.num1;
	//cout << obj2.num2;
	cout << obj2.num3;


	return 0;
}