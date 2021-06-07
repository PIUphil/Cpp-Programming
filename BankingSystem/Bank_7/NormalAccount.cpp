#include <iostream>
#include <string>
using namespace std;
#include "Account.h"
#include "NormalAccount.h"


NormalAccount::NormalAccount(string name, int id, int money, int rate)
	: Account(name, id, money), rate(rate) {}

// 입금처리과정
void NormalAccount::input(int money) {
	/*int don = money + (money * (rate / 100.0));
	Account::inMoney(don);*/
	Account::inMoney(money);				// 입금액
	Account::inMoney(money*(rate/100.0));		// 이자
}

