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
	updateEstoque();
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
			auxInt = line.find(',');
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
			/*auxProduto.preco = auxFloat;
			stream >> lixo;
			stream >> auxFloat;*/
			auxProduto.preco = auxFloat;

			//Inserindo a quantidade
			line.erase(0, 1);
			auxProduto.quantidade = std::stoi(line);
			
			produtosDispo.addElement(auxProduto);
    	}
    	readFile.close();
  	}
	
}

bool Estabelecimento::venda(std::string codigo, Cliente &cliente){
	
	for (int i = 0; i <= produtosDispo.lastIndex; i++){
		
		if (produtosDispo.getElementIndex(i).nome == codigo){
			if (cliente.comprar(produtosDispo.copyElementIndex(i))){
				produtosDispo.getElementIndex(i).quantidade--;
				for (int j = 0; j <= produtosVendi.lastIndex; j++){
					if (produtosDispo.getElementIndex(i).codigo == produtosVendi.getElementIndex(j).codigo){
						produtosVendi.getElementIndex(j).quantidade++;
						return true;
					}
					
				}
				Produto aux = produtosDispo.copyElementIndex(i);
				aux.quantidade = 1;
				produtosVendi.addElement(aux);
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
	for (int i = 0; i <= produtosVendi.lastIndex; i++){
		outputFile << produtosVendi.getElementIndex(i).toFile() << "\n";
		valArrecado += produtosVendi.getElementIndex(i).quantidade * produtosVendi.getElementIndex(i).preco;
	}
	outputFile << "Valor arrecadado final: R$" << valArrecado << "\n";
}

bool Estabelecimento::reabastecer(size_t quant, std::string produto){
	Produto searchProdut;
	searchProdut.nome = produto;
	searchProdut.quantidade = quant;
	if (fornecedor.repassarProdutos(searchProdut)){
		for (int i = 0; i <= produtosDispo.lastIndex; i++){
			if (produtosDispo.getElementIndex(i).nome == searchProdut.nome){
				produtosDispo.getElementIndex(i).quantidade = produtosDispo.getElementIndex(i).quantidade + quant;
				return true;
			}
		}
		// Aprimorar isso
	}
	return false;
	//return true;
}

VectorSup<Produto> Estabelecimento::listarFornecimento(){
	return fornecedor.getProdutos();
}

void Estabelecimento::updateEstoque(){
	std::ofstream outputFile("estoque.csv");
	outputFile << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE\n";
	for (int i = 0; i <= produtosDispo.lastIndex; i++){
		outputFile << produtosDispo.getElementIndex(i).toFile() << "\n";
	}
}