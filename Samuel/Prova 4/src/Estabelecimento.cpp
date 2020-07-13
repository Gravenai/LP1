#include "../include/Estabelecimento.hpp"

Estabelecimento::Estabelecimento(){

	loadProdutos();
}

Estabelecimento::Estabelecimento(std::string fileName){
	loadProdutos();
	this->fileName = fileName;
}

Estabelecimento::~Estabelecimento(){
	caixa();
	
}

void Estabelecimento::loadProdutos(){
	std::ifstream readFile(fileName);
	std::string line;
	
	if (readFile.is_open()){
		getline (readFile,line);

    	while ( getline (readFile,line) ){
    		Produto auxProduto;
    		int auxInt = 0;
			std::string aux;

			// Inserindo o codigo
			auxInt = line.find(',');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);
			auxProduto.codigo = std::stoi(aux);

			// Inserindo o nome
			auxInt = line.find(',');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);
			auxProduto.nome = aux;

			// Inserindo a unidade de medida
			auxInt = line.find('.');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);
			auxProduto.unidadeMedida = aux;

			// Inserindo o preco
			auxInt = line.find(' ');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);

			auxInt = line.find('"');
			aux = line.substr(0, auxInt);
			line.erase(0, auxInt + 1);

			std::stringstream stream(aux);

			float auxFloat = 0;
			char lixo;

			stream >> auxFloat;
			auxProduto.preco = auxFloat;
			stream >> lixo;
			stream >> auxFloat;
			auxProduto.preco = auxProduto.preco + (auxFloat/100);

			//Inserindo a quantidade
			line.erase(0, 1);
			auxProduto.quantidade = std::stoi(line);
			
			produtosDispo.push_back(auxProduto);
    	}
    	readFile.close();
  	}
	
}

bool Estabelecimento::venda(int codigo, Cliente &cliente){
	for (auto &i : produtosDispo){
		if (i.codigo == codigo){
			if (cliente.comprar(i)){
				i.quantidade--;
				for (auto &j : produtosVendi){
					if (i.codigo == j.codigo){
						j.quantidade++;
						return true;
					}
					
				}
				Produto aux = i;
				aux.quantidade = 1;
				produtosVendi.push_back(aux);
				return true;
			} else {
				return false;
			}
		}
	}
	return false;
}


void Estabelecimento::caixa(){
	double valArrecado = 0;
	std::ofstream outputFile("caixa.csv");
	outputFile << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE\n";
	for (auto i : produtosVendi){
		outputFile << i.toFile() << "\n";
		valArrecado += i.quantidade * i.preco;
	}
	outputFile << "Valor arrecadado final: R$" << valArrecado << "\n";
}

/*void Estabelecimento::updateEstoque(){
	std::ofstream outputFile("estoque.csv");
	outputFile << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE\n";
	for (auto i : produtosDispo){
		outputFile << i.toFile() << "\n";
	}
}*/