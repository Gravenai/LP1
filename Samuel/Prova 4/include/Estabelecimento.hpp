#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <vector>
#include <string>
#include "Produto.hpp"
#include "Cliente.hpp"
#include <fstream>
#include <sstream>

class Estabelecimento {
	public:
	std::vector<Produto> produtosDispo;
	std::vector<Produto> produtosVendi;
	std::string fileName = "estoque.csv";

	Estabelecimento();
	Estabelecimento(std::string fileName);
	~Estabelecimento();
	std::vector<std::string> listar();
	bool venda(int codigo, Cliente &cliente);
	void caixa();

	private:
	void loadProdutos();
};

#endif