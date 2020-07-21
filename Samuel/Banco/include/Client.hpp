#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Bank.hpp"

class Client{
	private:
		std::string name;
		Bank agency;
		static int quantClient;

	public:
		Client(std::string name);
		std::string getName();
		void setName(std::string name);
		Bank getAgency();
		void setAgency(Bank bank);

};

#endif