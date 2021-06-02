/*
  계산기(Calculator) 객체
  - 두 개의 정수를 입력받아 덧셈을 계산하여 반환하는 로직
  - 두 개의 멤버필드, 두 개의 메서드(생성자메서드 포함)
  - main.cpp, Calculator.cpp, Calculator.h 구분
  - Adder.cpp, Adder.h
*/

#include <iostream>
using namespace std;

#include "Calculator.h"

int main() {
	Calculator calc;		// 객체생성
	calc.run();				// 계산기 시작

	return 0;
}