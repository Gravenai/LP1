#include "../include/Fornecedor.hpp"

// PRIVATE:

void Fornecedor::loadProdutos(){
	std::ifstream readFile(fileName);
	std::string line;

	if (readFile.is_open()){
		getline (readFile,line);
		while ( getline (readFile,line) ){
			Produto auxProduto;
    		int auxInt = 0;
			std::string aux;

			// Inserindo o nome
			auxInt = line.find(',');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);
			auxProduto.nome = aux;

			// Inserindo a quantidade
			auxProduto.quantidade = std::stoi(line);

			vs.addElement(auxProduto);
			
		}
	}
}

// PUBLIC

Fornecedor::Fornecedor(){
	
	loadProdutos();
}

Fornecedor::~Fornecedor(){
	updateFornecedor();
}

VectorSup<Produto> Fornecedor::getProdutos(){
	return vs;
}

bool Fornecedor::repassarProdutos(Produto produto){
	for (int i = 0; i <= vs.lastIndex; i++){
		if (produto.nome == vs.getElementIndex(i).nome && produto.quantidade <= vs.getElementIndex(i).quantidade){

			vs.getElementIndex(i).quantidade -= produto.quantidade;
			return true;
		}
	}
	return false;
}

void Fornecedor::updateFornecedor(){
	std::ofstream outputFile("fornecedor.csv");
	outputFile << "PRODUTO,QUANTIDADE\n";
	for (int i = 0; i <= vs.lastIndex; i++){
		outputFile << vs.getElementIndex(i).toFileResumed() << "\n";
	}
}