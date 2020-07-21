#include "../include/Produto.hpp"

#include <iostream>
Produto::Produto(){

}

Produto::Produto(std::string nome, int codigo, double preco, std::string unidadeMedida, int quantidade){
	this->nome = nome;
	this->codigo = codigo;
	this->preco = preco;
	this->unidadeMedida = unidadeMedida;
	this->quantidade = quantidade;
}

std::string Produto::toString(){
	std::stringstream stream;
	char twoCases[20];
	sprintf(twoCases, "%.2f", preco);
	stream << codigo << " - " << nome << "| R$ " << twoCases << " " << unidadeMedida << " | " << quantidade;
	return stream.str();
}

std::string Produto::toStringResumed(){
	std::stringstream stream;
	stream << nome << " | " << quantidade;
	return stream.str();
}

std::string Produto::toFile(){
	std::stringstream stream;

	char twoCases[20];
	sprintf(twoCases, "%.2f", preco);

	stream << codigo << "," << nome << "," << unidadeMedida << ",\"R$ " << twoCases << "\"," << quantidade;
	return stream.str();
}

std::string Produto::toFileResumed(){
	std::stringstream stream;

	stream << nome << "," << quantidade;
	return stream.str();
}