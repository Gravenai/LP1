#ifndef CLIENTPF_H
#define CLIENTPF_H

#include <string>
#include "Client.hpp"

class ClientPF : public Client{
	private:
		int cpf;

	public:
		ClientPF(std::string name);
		int getCpf();
		void setCpf(int cpf);
};

#endif