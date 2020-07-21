#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "Produto.hpp"
#include "VectorSup.hpp"
#include <fstream>
#include <string>

//Ajuste o encapsulamento caso sobre tempo
class Fornecedor {
	private:
		void loadProdutos();

	public:

		VectorSup<Produto> vs;
		std::string fileName = "fornecedor.csv";

		Fornecedor();
		~Fornecedor();

		VectorSup<Produto> getProdutos();
		bool repassarProdutos(Produto produto);
		void updateFornecedor();
};

#endif