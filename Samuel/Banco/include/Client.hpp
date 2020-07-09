#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Bank.hpp"

class Client{
	public:
		std::string name;
		int cpf;
		Bank agency;
		static int quantClient;

		Client();
};

#endif