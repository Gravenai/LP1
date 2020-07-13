#ifndef CLIENTE_H
#define CLIENTE_H

#include "Produto.hpp"
#include <vector>
#include <fstream>
#include <sstream>

class Cliente {
	public:
	float saldo;
	std::vector<Produto> sacola;
	int static quantClientes;

	Cliente();
	~Cliente();
	bool comprar(Produto produto);
	void registro();
};

#endif