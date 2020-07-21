#ifndef ACOOUNT_H
#define ACOOUNT_H

#include <string>
#include "Client.hpp"

class Account {
	public:
	std::string name;
	int cpf;
	double balance;
	static int quantAccount;

	Account();
	~Account();
	void deposit(double money);
	void withdraw(double money);
	void transfer(Account account, double money);
};

#endif