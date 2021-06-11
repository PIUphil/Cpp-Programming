/*
  로또 복권 프로그램
  STL 을 이용한(벡터) 프로젝트
  구입할 로또 개수를 입력받고, 당첨번호 6개와 보너스 번호 1개를 이용하여
  사용자가 구매한 로또 복권의 당첨여부를 출력하는 프로그램
  
  <처리조건>
  - 로또는 1~45 사이의 번호를 중복없이 무작위로 6개를 추출
  - 랜덤으로 발생시킨 당첨번호를 벡터에 저장
  - 사용자가 구입한 로또의 개수를 이용한 응모번호를 랜덤으로 추출
  - 응모한 번호와 함께 등수를 저장하기 위한 클래스 구현

  <입력 및 출력형식>
  로또 복권 프로그램
  ********************************************************
   1등(6개 숫자 일치, 보너스 제외) : 상금 1,800,000,000원
   2등(5개 숫자 일치, 보너스 포함) : 상금   200,000,000원
   3등(5개 숫자 일치, 보너스 제외) : 상금    30,000,000원
   4등(4개 숫자 일치, 보너스 제외) : 상금     2,000,000원
   5등(3개 숫자 일치, 보너스 제외) : 상금         5,000원
  ********************************************************
  구매할 로또 개수 = 

  응모한 번호
  ********************************************************
   No 1 : 
   No 2 : 
   No 3 : 
   No 4 : 
     ⁝
   
  ********************************************************
  당첨번호 :
  보너스   :
  ********************************************************
  당첨등수(당첨금) : 
  당첨된 응모번호 추출 : 
*/

#include <iostream>
#include <time.h>               // 랜덤처리
#include <vector>
#include <set>                  // 중복없이 숫자를 처리
#include <algorithm>
using namespace std;

// 출력을 위한 전역함수
void PrintElement(int n) {
    cout << n << "\t";
}

// 로또 번호를 저장하는 클래스 선언
class LottoGenerator {
public:
    vector<int> ball;              // 로또번호를 저장할 벡터 선언

    // 6개의 로또숫자와 보너스를 포함한 로또숫자를 생성하는 생성자 메서드
    LottoGenerator() {
        makeRandom(6);
    }

    LottoGenerator(int count) {         // 당첨번호와 보너스번호를 추출하는 메서드
        makeRandom(count);
    }

    // 랜덤으로 로또번호를 생성하여 set에 저장 후 리턴
    set<int> RangeRandDemo(int range_min, int range_max, int n) {
        set<int> s;

        while (true) {
            // 하나의 난수 발생
            int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;

            // 발생한 난수 set에 저장
            s.insert(u);
            if (s.size() >= n) break;
        }
        return s;
    }

    void makeRandom(int count) {
        set<int> s;

        s = RangeRandDemo(1, 46, count);

        set<int>::iterator iter;
        for (iter = s.begin(); iter != s.end(); iter++)
            ball.push_back(*iter);
    }

    // 로또번호를 출력하는 전역함수
    void lottoprn() {
        for_each(this->ball.begin(), this->ball.end(), PrintElement);
        cout << endl;
    }
};

// 사용자가 응모한 로또 번호와 당첨순위를 담는 클래스
class UserLotto {
public:
    int pos;                            // 당첨된 응모복권 번호
    LottoGenerator lotto;
    int grade;                          // 당첨순위

    UserLotto() {
        grade = 0;
    }
};

// 전역함수
void line() {
    cout << "********************************************************\n";
}

void title() {
    cout << "\t" << "로또 복권 프로그램\n";
    line();
    cout << "1등(6개 숫자 일치, 보너스 제외) : 상금 1,800,000,000원" << endl;
    cout << "2등(5개 숫자 일치, 보너스 포함) : 상금   200,000,000원" << endl;
    cout << "3등(5개 숫자 일치, 보너스 제외) : 상금    30,000,000원" << endl;
    cout << "4등(4개 숫자 일치, 보너스 제외) : 상금     2,000,000원" << endl;
    cout << "5등(3개 숫자 일치, 보너스 제외) : 상금         5,000원" << endl;
    line();
}

// 당첨여부와 상금을 출력하는 함수
void Lotto(UserLotto user) {
    switch (user.grade) {
    case 1:
        cout << "1등(총상금 1,800,000,000원) : "; 
        break;
    case 2:
        cout << "2등(총상금   200,000,000원) : ";
        break;
    case 3:
        cout << "3등(총상금    30,000,000원) : ";
        break;
    case 4:
        cout << "4등(총상금     2,000,000원) : ";
        break;
    case 5:
        cout << "5등(총상금         5,000원) : ";
        break;
    }

    if (user.grade >= 1 && user.grade <= 5) {
        cout << "\n NO " << user.pos << " : ";
        user.lotto.lottoprn();
    }
}

// 응모번호와 당첨번호를 비교하여 일치하는 개수에 따른 순위
void counts(vector<UserLotto> user, LottoGenerator lotto) {
    int matchingcount;

    vector<int>::iterator num1, num2;
    // 사용자가 응모한 개수만큼 반복처리
    for (int i = 0; i < user.size(); i++) {
        matchingcount = 0;

        // 당첨번호와 사용자번호를 비교하는 작업
        for (num1 = lotto.ball.begin(); num1 < lotto.ball.end() - 1; num1++) {
            for (num2 = user[i].lotto.ball.begin(); num2 < user[i].lotto.ball.end(); num2++) {
                if (*num1 < *num2) {
                    break;
                }
                if (*num1 == *num2) {
                    matchingcount++;
                }
            }
        }

        switch (matchingcount) {
        case 3:                     // 일치하는 개수가 3이면
            user[i].grade = 5;
            break;
        case 4:
            user[i].grade = 4;
            break;
        case 5: {                    // 당첨번호(6+1) - 사용자(6)
            user[i].grade = 3;
            // 이 때 보너스 번호가 일치하면 2등
            int bonus = *(lotto.ball.end() - 1);

            vector<int>::iterator iter;
            // find(시작위치, 마지막위치, 찾을 값)
            iter = find(user[i].lotto.ball.begin(), user[i].lotto.ball.end(), bonus);
            if (iter != user[i].lotto.ball.end()) {
                user[i].grade = 2;
            }
            break;
        }
        case 6:                     // 일치하는 개수가 6
            user[i].grade = 1;
            break;
        default:
            user[i].grade = 0;
        }
        Lotto(user[i]);
    }
}


int main() {
    // 사용자가 응모할 로또번호를 저장할 객체
    vector<UserLotto> user;
    int userCount;
    int pos = 1;
    int i;

    title();
    cout << "구매할 로또 개수 = ";
    cin >> userCount;                   // 5

    cout << "응모한 번호 : \n";
    line();

    for (i = 0; i < userCount; i++) {
        UserLotto userlotto;
        userlotto.pos = i + 1;
        cout << "NO " << userlotto.pos << " : ";
        userlotto.lotto.lottoprn();
        user.push_back(userlotto);
    }

    // 당첨번호 추출
    LottoGenerator lotto(7);        // 당첨번호 6 + 보너스 1
    line();

    cout << "당첨번호 : ";
    lotto.lottoprn();

    cout << "보너스   : " << lotto.ball[6] << endl;
    line();

    counts(user, lotto);


    return 0;
}


