#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person {      // 사람을 모델링
    // 접근제한자
    // 멤버필드

    // 접근제한자
    // 멤버메서드
public:                 // 접근제한자
    string name;        // 멤버필드

public:                 // 접근제한자

    // 생성자 메서드 : 객체가 생성될 때 자동으로 호출되는 메서드
    Person(string irum) {          // default constructor(디폴트 생성자) - 기본으로 클래스명과 동일하게 생성. 생략되어있었음.
    // 객체가 생성될 때 수행할 작업을 기술
    // 멤버필드를 초기화시켜주는 역할을 수행한다.
        name = irum;
    }


    void walk(int speed) {   // 멤버메서드(함수)
        cout << name << "이 " << speed << "의 속도로 걸어갑니다" << endl;
    }

    void run(int speed) {
        cout << name << "이 " << speed << "의 속도로 뛰어갑니다" << endl;
    }
};