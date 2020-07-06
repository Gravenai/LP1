#include "../include/Account.hpp"

Account::Account(){

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
