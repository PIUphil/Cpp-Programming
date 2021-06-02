#include <iostream>
using namespace std;

#include "Calculator.h"
#include "Adder.h"

void Calculator::run() {
	cout << "두 개의 정수 입력 = ";
	int su1, su2;
	cin >> su1 >> su2;

	Adder adder(su1, su2);
	cout << adder.process();
}