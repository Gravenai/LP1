#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Empresa.hpp"

class Funcionario{
	private :
		std::string nome;
		Empresa *empresa;
		std::string departamento;
		std::string dataAdmis;
		float salario;

	public :
		Funcionario();
		Funcionario(std::string nome, Empresa empresa, std::string departamento, std::string dataAdmis);
		~Funcionario();

		std::string getNome();
		void setNome(std::string nome);
		Empresa* getEmpresa();
		void setEmpresa(Empresa empresa);
		std::string getDepartamento();
		void setDepartamento(std::string departamento);
		std::string getDataAdmis();
		void setDataAdmis(std::string dataAdmis);
		float getSalario();
		void setSalario(float salario);

};

#endif