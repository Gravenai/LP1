#include "../include/Cliente.hpp"

int Cliente::quantClientes;

Cliente::Cliente(){

}

Cliente::~Cliente(){
	registro();
}

bool Cliente::comprar(Produto produto){

	if (saldo >= produto.preco){
		saldo -= produto.preco;
		int count = 0;
		for (auto &i : sacola){
			count++;
			if (i.codigo == produto.codigo){
				i.quantidade++;
				
				return true;
			}
		}
		produto.quantidade = 1;
		sacola.push_back(produto);
		
		return true;
	}
	return false;
}

void Cliente::registro(){
	std::stringstream stream;
	stream << "clientes/cliente_" << quantClientes << ".txt";
	std::ofstream outputFile(stream.str());

	for (auto i : sacola){
		outputFile << i.toFile() << "\n";
	}
}