#ifndef FRONT_H
#define FRONT_H

#include <vector>
#include <string>
#include <iostream>
#include "Estabelecimento.hpp"
#include "Cliente.hpp"

class Front {
	public:

	Estabelecimento estabelecimento;
	
	Front();
	Front(std::string fileName);
	int run();
	void listar();
	void listar(Cliente &cliente);
	void listarFornecimento();
	void comprar(std::string codigo, Cliente &cliente);
	void reabastecerEstoque(size_t quant, std::string nome);
	static void exibirMenu();

};

#endif