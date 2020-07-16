#ifndef CLIENTPJ_H
#define CLIENTPJ_H

#include <string>
#include "Bank.hpp"

class ClientPJ{
	public:
		std::string razaoSocial;
		std::string cnpj;
		Bank agency;
		static int quantClient;

		ClientPJ();
};

#endif