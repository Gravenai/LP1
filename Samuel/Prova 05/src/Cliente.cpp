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

		for (int i = 0; i <= sacola.lastIndex; i++){
			count++;
			if (sacola.getElementIndex(i).codigo == produto.codigo){
				sacola.getElementIndex(i).quantidade++;
				
				return true;
			}
		}
		produto.quantidade = 1;
		sacola.addElement(produto);
		
		return true;
	}
	return false;
}

void Cliente::registro(){
	std::stringstream stream;
	stream << "clientes/cliente_" << quantClientes << ".txt";
	std::ofstream outputFile(stream.str());

	for (int i = 0; i <= sacola.lastIndex; i++){
		outputFile << sacola.getElementIndex(i).toFile() << "\n";
	}
}