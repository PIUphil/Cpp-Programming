/*
  제어문
  - 프로그램의 흐름이나 순서를 제어할 때 사용하는 문장
  - 일반적으로 위에서 아래로, 좌에서 우로 진행된다.
  - 종류 : 조건문, 반복문, 기타제어문

  1. 조건문
    - 조건식에 의해 문장을 제어한다.
    - 조건식은 그 결과가 참 또는 거짓으로 판정되는 식
    - 조건식은 비교연산자나 논리연산자가 올 수 있다.
    - 종류 : 단순if문, if~else문, else if문, switch~case문

    - 단순if문 : 주어진 조건식이 참일 때만 문장을 제어할 때 사용
      if(조건식) {                                 // {} : 블럭. 제어할 때 씀
        // 조건식이 참일 때 실행할 문장
      }

    - if~else : 조건이 참이나 거짓일 때 실행할 문장을 제어
      if(조건식) {
        // 조건식이 참일 때 실행할 문장
      }
      else {
        // 조건식이 거짓일 때 실행할 문장
      }

    - 다중if문(else if) : if문 안에 또 다른 if문을 담는 문장
                         여러 개의 조건에 의해 문장을 제어할 때 사용
      if(조건식1) {
        // 조건식 1이 참일 때
      }
      else if(조건식2) {
        // 조건식 2가 참일 때
      }
      else {
        // 조건식1, 2가 모두 거짓일 때
      }

    - switch ~ case문 : 다중if문을 간소화한 형태   // 다중if는 순서대로 처리하지만, 스위치는 해당되는것만 처리하므로 빠름
      switch(값 or 수식 - 정수형) {
      case 값1 : 실행할 문장
      case 값2 : 실행할 문장
      case 값n : 실행할 문장 (모든 경우를 다 잡아줘야함)
      default : case에 해당되는 값이 없을 경우 실행할 문장
      }
*/

#include <iostream>
using namespace std;

/*
// 하나의 숫자를 입력받아 양수인지 판단하는 프로그램
int main() {
    // 선언문
    int num;

    // 입력문
    cout << "수 = ";
    cin >> num;

    // 처리문

    // 출력문
    if(num > 0)                         // 하나일 땐 블럭({})을 사용하지않아도 됨
        cout << "양수입니다." << endl;
    
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}*/

/*
// 입력받은 수가 양수인지 음수인지 판정하는 프로그램
int main() {
    int num;

    cout << "수 = ";
    cin >> num;

    if (num > 0) 
        cout << "양수입니다." << endl;  
    else
        cout << "음수입니다?" << endl;  // 0 : 음수
    
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}*/

// 양수와 음수 그리고 0을 판정하는 프로그램
int main() {
    int num;

    cout << "number = ";
    cin >> num;

    if (num > 0)
        cout << "양수" << endl;
    else if (num < 0)
        cout << "음수" << endl;
    else
        cout << "0입니다" << endl;

    cout << "프로그램을 종료합니다." << endl;

    return 0;
}