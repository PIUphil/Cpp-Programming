/*
  객체 => 클래스 : 접근제한자, 멤버필드, 멤버메서드
		- 재활용 : 소프트웨어의 위기 => 소프트웨어 공학
		- 오픈소스

  클래스 : 멤버필드 - 객체의 특성(or 속성)
		   멤버메서드 - 객체의 행위나 행동
		   접근제한자 - private, protected, public

  "나는 사과장수에게 2000원 어치의 사과를 구매했다."
  객체 : 나, 사과장수, 사과(IOT - 사물인터넷)
  나 => 멤버필드(돈, 구매한 사과), 멤버메서드(사과를 구매)
  사과장수 => 멤버필드(판매할 사과, 사과가격), 멤버메서드(판매)
*/
#include <iostream>
using namespace std;

// 클래스 선언부..... x
class AppleSeller {
	// 멤버필드
	int apples;
	int price;
	int sales;					// 매출금액

public:
	void init(int apples, int price) {
		this->apples = apples;
		this->price = price;
		sales = 0;
	}

	int appleSales(int money) {
		int apple = money / price;
		apples -= apple;
		sales += money;

		return apple;
	}

	void salesResult() {
		cout << "남은 사과 수 : " << apples << endl;
		cout << "매출금액 : " << sales << endl;
	}
};


class AppleBuyer {
	// 멤버필드 - 속성 or 상태
	int money;
	int numOfApple;

public:		// 멤버메서드 - 행위 or 행동
	void init(int money) {
		this->money = money;
		numOfApple = 0;
	}	

	void buy(AppleSeller& seller, int don) {
		//int don = 2000;		// 사과를 구매할 금액
		money -= don;
		numOfApple=seller.appleSales(don);
	}

	void buyerResult() {
		cout << "구매한 사과 수 : " << numOfApple << endl;
		cout << " 남은 돈 : " << money << endl;
	}
};


int main() {
	AppleBuyer buyer;
	AppleSeller seller;

	buyer.init(10000);
	seller.init(50, 1000);

	buyer.buyerResult();
	buyer.buy(seller, 2000);
	buyer.buyerResult();
	seller.salesResult();

	return 0;
}