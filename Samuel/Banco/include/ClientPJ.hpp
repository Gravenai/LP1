#ifndef CLIENTPJ_H
#define CLIENTPJ_H

#include <string>
#include "Client.hpp"

class ClientPJ : public Client{
	private:
		std::string razaoSocial;
		std::string cnpj;

	public:
		ClientPJ(std::string name);
		std::string getRazaoSocial();
		void setRazaoSocial(std::string razaoSocial);
		std::string getCnpj();
		void setCnpj(std::string cnpj);
};

#endif