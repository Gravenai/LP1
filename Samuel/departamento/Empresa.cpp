#include "Empresa.hpp"

Empresa::Empresa(){

}

Empresa::Empresa(std::string nome, std::string cnpj){
	this->nome = nome;
	this->cnpj = cnpj;
}

Empresa::~Empresa(){

}

std::string Empresa::getNome(){
	return nome;
}

void Empresa::setNome(std::string nome){
	this->nome = nome;
}

std::string Empresa::getCnpj(){
	return cnpj;
}

void Empresa::setCnpj(std::string cnpj){
	this->cnpj = cnpj;
}