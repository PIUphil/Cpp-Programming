/*
  객체 지향 프로그래밍(OOP, Object-Oriented Programming)			// 모듈
  - 모든 데이터를 객체(Object)로 취급하여 처리하는 객체 중심 프로그래밍
  - 세상의 모든 것은 객체
  - 특징 : 추상화, 캡슐화, 정보은닉, 상속성, 다형성

  클래스와 객체
  - 클래스(class) : 객체(Object)를 모델링 하는 것 // 구체화,프로그래밍 하는 것
    자료구조 : 변수, 배열, 구조체                        // 데이터를 관리하고 사용
    멤버변수(property) - 속성, 멤버메서드(method, 함수)-행위 행동, 상태    // 클래스를 구성하는 것
    접근제한자(접근지정자) : private, public, protected

  - 객체(Object)와 객체(instance)
*/

#include <iostream>
#include <string>       // string 클래스 포함
using namespace std;
#include "Person.h"     // 내가 만든 헤더파일은 ""로 불러옴


int main() {
    // 객체(instance)를 생성해야 한다.
    Person p("홍길동");
    // p.name = "홍길동";

    Person q("장보고");
    // q.name = "장보고";

    Person w("김유신");
    // w.name = "김유신";

    // 객체를 이용해서 멤버에 접근 : direct연산자(.)
    p.walk(5);
    p.run(10);

    q.run(10);
    q.walk(15);

    w.walk(20);

    return 0;
}

// 클래스 쓰는 이유 - 재활용