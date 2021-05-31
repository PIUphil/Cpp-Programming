/*
  대입연산자(=)와 배정대입연산자(+=, -=, *=, /=, %=)
  증감연산자 : 1씩 증가와 감소를 수행하는 연산자, 단항연산자
  - 증가 : ++ 
  - 감소 : --
  - 우선순위 : 전위증감연산 / 후위증감연산
    전위 : ++변수, --변수 (우선순위 제일 높음)
    후위 : 변수++, 변수--
    최우선연산자 : (), [배열], .(direct연산자), 
                   단항연산자(전위증감연산자, 논리부정(!), 비트부정(~), 부호연산(+/-)
*/

#include <iostream>
using namespace std;

int main() {
    /*int num1 = 8;
    int num2 = 8;
    int num3 = 8;*/
    int num1, num2, num3;
    num1 = num2 = num3 = 8;         // 연산방향 ←

    num1 = num1 + 5;
    num2 += 5;          // num2 = num2 + 5;
    num3 = +5;          // 단순 대입 연산자. num3에 5를 넣으라는 의미.. (권장x)

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    
    return 0;
}