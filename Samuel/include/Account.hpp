#ifndef ACOOUNT_H
#define ACOOUNT_H

#include <string>

class Account {
	public:
	std::string name;
	int cpf;
	double balance;

	Account();
	~Account();
	void deposit(double money);
	void withdraw(double money);
	void transfer(Account account, double money);
};

#endif