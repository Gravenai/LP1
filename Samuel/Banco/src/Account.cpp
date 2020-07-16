#include "../include/Account.hpp"

int Account::quantAccount;

Account::Account(){
	this->quantAccount+=1;
}
Account::~Account(){
	
}

void Account::deposit(double money){
	this->balance += money;
}
void Account::withdraw(double money){
	this->balance -= money;	
}
void Account::transfer(Account account, double money){
	this->balance -= money;
	account.balance += money;
}
