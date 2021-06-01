#include <iostream>
using namespace std;

struct Prop {
	int saving;		// 적금
	int loan;		// 대출
};

// 함수 선언
int CalcProperty(int, int);


int main() {
	int hong;
	Prop aaa = {10000000, 4000000};		// 천만, 400만
	
	hong = CalcProperty(aaa.saving, aaa.loan);

	cout << "홍길동의 재산은 적금 " << aaa.saving << "원이고, " << endl;
	cout << "대출 " << aaa.loan << "을 제외한 총 " << hong << "원이다." << endl;
	
	return 0;
}


// 함수 정의
int CalcProperty(int s, int l) {
	return s - l;
}
