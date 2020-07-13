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
	void listar(Cliente cliente);
	void comprar(int codigo, Cliente &cliente);
	static void exibirMenu();

};

#endif