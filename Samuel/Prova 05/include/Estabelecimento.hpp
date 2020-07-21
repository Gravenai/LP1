#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <vector>
#include <string>
#include "Produto.hpp"
#include "Cliente.hpp"
#include "Fornecedor.hpp"
#include "VectorSup.hpp"
#include <fstream>
#include <sstream>

class Estabelecimento {
	public:
	VectorSup<Produto> produtosDispo;
	VectorSup<Produto> produtosVendi;
	Fornecedor fornecedor;
	std::string fileName = "estoque.csv";

	Estabelecimento();
	Estabelecimento(std::string fileName);
	~Estabelecimento();

	VectorSup<std::string> listar();
	VectorSup<Produto> listarFornecimento();
	bool venda(std::string codigo, Cliente &cliente);
	bool reabastecer(size_t quant, std::string produto);
	void updateEstoque();
	void caixa();

	private:
	void loadProdutos();
};

#endif