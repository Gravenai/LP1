#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>

class Empresa{
	private :
		std::string nome;
		std::string cnpj;
		
	public :
		Empresa();
		Empresa(std::string nome, std::string cnpj);
		~Empresa();
		std::string getNome();
		void setNome(std::string nome);
		std::string getCnpj();
		void setCnpj(std::string cnpj);
};

#endif