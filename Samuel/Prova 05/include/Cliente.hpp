#ifndef CLIENTE_H
#define CLIENTE_H

#include "Produto.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "VectorSup.hpp"

class Cliente {
	public:
	float saldo;
	VectorSup<Produto> sacola;
	int static quantClientes;

	Cliente();
	~Cliente();
	bool comprar(Produto produto);
	void registro();
};

#endif