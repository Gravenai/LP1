#include "Funcionario.hpp"

Funcionario::Funcionario(){

}

Funcionario::Funcionario(std::string nome, Empresa empresa, std::string departamento, std::string dataAdmis){
	this->nome = nome;
	this->empresa = &empresa;
	this->departamento = departamento;
	this->dataAdmis = dataAdmis;
}

Funcionario::~Funcionario(){

}

std::string Funcionario::getNome(){
	return nome;
}

void Funcionario::setNome(std::string nome){
	this->nome = nome;
}

Empresa* Funcionario::getEmpresa(){
	return empresa;
}

void Funcionario::setEmpresa(Empresa empresa){
	this->empresa = &empresa;
}

std::string Funcionario::getDepartamento(){
	return departamento;
}

void Funcionario::setDepartamento(std::string departamento){
	this->departamento = departamento;
}

std::string Funcionario::getDataAdmis(){
	return dataAdmis;
}

void Funcionario::setDataAdmis(std::string dataAdmis){
	this->dataAdmis = dataAdmis;
}

float Funcionario::getSalario(){
	return salario;
}

void Funcionario::setSalario(float salario){
	this->salario = salario;
}