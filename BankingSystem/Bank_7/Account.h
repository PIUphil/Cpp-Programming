#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
	string name;
	int id;
	int balance;

public:
	Account(string name, int id, int money);

	void setName(string name);
	string getName() const;
	int getId() const;
	int getBalance() const;
	void inMoney(int money);
	int outMoney(int money);
	void showAllAccount() const;

	// Account => Normal, High
	virtual void input(int money);
};