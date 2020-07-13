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
	stream << codigo << " - " << nome << "| R$ " << preco << " " << unidadeMedida << " | " << quantidade;
	return stream.str();
}

std::string Produto::toFile(){
	std::stringstream stream;

	std::stringstream convertStream;
	convertStream << preco;

	std::string aux = convertStream.str();
	size_t localComma = aux.find('.');
	if (localComma == aux.size() - 2){
		convertStream << "0";
	}

	stream << codigo << "," << nome << ",\"R$ " << aux << "\"," << unidadeMedida << "," << quantidade;
	return stream.str();
}