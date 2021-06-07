#include <iostream>
#include <string>
using namespace std;

#include "Account.h"
#include "HighAccount.h"

HighAccount::HighAccount(string name, int id, int balance, int rate, int special)
	: Account(name, id, balance), rate(rate), special(special) {}

void HighAccount::input(int money) {
	Account::inMoney(money);					// 원금
	Account::inMoney(money*(rate/100.0));		// 이자
	Account::inMoney(money * (special / 100.0));// 특별이자
}