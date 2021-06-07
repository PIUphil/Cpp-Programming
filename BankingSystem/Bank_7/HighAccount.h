#pragma once
#include <string>
#include "Account.h"

class HighAccount : public Account {
	int rate;
	int special;

public:
	HighAccount(string name, int id, int balance, int rate, int special);
	
	void input(int money);
};