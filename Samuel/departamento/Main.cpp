#include "Funcionario.hpp"
#include "Empresa.hpp"
#include <iostream>

int main(){
	Empresa empresa("Eduardo importados", "62.353.417/0001-95");
	std::cout << "Quer cadastrar quantos funcionarios?\n";
	int count;
	std::cin >> count;
	
	Funcionario novoFuncionario[count];
	for (size_t i = 0; i < count; i++){
		
		std::cout << "Digite as informações do funcionario\n";

		std::string nome;
		float salario;

		std::cout << "Digite o nome: ";
		std::cin >> nome;
		novoFuncionario[i].setNome(nome);
		
		std::cout << "Digite o nome do departamento: ";
		std::cin >> nome;
		novoFuncionario[i].setDepartamento(nome);

		std::cout << "Digite a data de admissão: ";
		std::cin >> nome;
		novoFuncionario[i].setDataAdmis(nome);

		std::cout << "Digite o salario: ";
		std::cin >> salario;
		novoFuncionario[i].setSalario(salario);

		novoFuncionario[i].setEmpresa(empresa);
	}

	std::cout << "Digite qual departamento você deseja dar um aumento\n";
	std::string depAum;
	std::cin >> depAum;
	for (size_t i = 0; i < count; i++){
		if (novoFuncionario[i].getDepartamento() == depAum){
			novoFuncionario[i].setSalario(novoFuncionario[i].getSalario() * 1.10);
		}
	}
	return 0;
}