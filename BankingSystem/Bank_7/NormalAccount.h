#pragma once
#include <string>
#include "Account.h"

class NormalAccount : public Account {
	int rate;				// 이자율(단위 %)

public:
	NormalAccount(string name, int id, int money, int rate);
	void input(int money);
};