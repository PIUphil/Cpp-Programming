// 참조리턴 함수
#include <iostream>
using namespace std;
/*
void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
	cout << "swap : " << a << " : " << b << endl;

	// return;  지역변수는 소멸됨.
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
	cout << "swap : " << *a << " : " << *b << endl;
}*/

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
	cout << "swap : " << a << " : " << b << endl;

	// return;  지역변수는 소멸됨.
}


int& FuncOne(int& a) {		
	a++;
	return a;				// 리턴값 -> 참조값
}

int FuncTwo(int& a) {
	a++;
	return a;				
}

int main() {
	int num1 = 5;
	int &num2 = FuncOne(num1);		// int& num2 = num1;
	int num3 = FuncTwo(num1);

	cout << num1 << " : "  << num2 << " : " << num3 << endl;
	/*
	int a = 10, b = 20;
	cout << "main : " << a << " : " << b << endl;

	swap(a, b);
	cout << "main : " << a << " : " << b << endl;*/

	/*swap(&a, &b);
	cout << "main : " << a << " : " << b << endl;*/

	return 0;
}
