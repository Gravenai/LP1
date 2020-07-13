#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <sstream>

class Produto {
	public:
	std::string nome;
	int codigo;
	int quantidade;
	double preco;
	std::string unidadeMedida;

	Produto();
	Produto(std::string nome, int codigo, double preco, std::string unidadeMedida, int quantidade);
	std::string toString();
	std::string toFile();
};

#endif