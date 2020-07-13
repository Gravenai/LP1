#include "../include/Front.hpp"

Front::Front(){

}

Front::Front(std::string fileName){
	Estabelecimento aux(fileName);
	this->estabelecimento = aux;
	
}

int Front::run(){
	
	char cliente = 's';

	std::cout << "Deseja inicializar um novo cliente? (s/n)\n";
	std::cin >> cliente;
	
	while (cliente != 'n'){
		
		Cliente novoCliente;
		std::cout << "Digite o saldo do novo cliente\n";
		std::cin >> novoCliente.saldo;
		int action = -1;
		while (action != 4){
			exibirMenu();
			std::cin >> action;
			std::cout << "\n";
			switch (action){
				case 1:
					listar();
				break;
				case 2:
					std::cout << "Digite o codigo de um produto: \n";
					int codigo;
					std::cin >> codigo;
					comprar(codigo, novoCliente);
					
				break;
				case 3:
					listar(novoCliente);
				break;
				case 4:
					novoCliente.quantClientes++;
					
				break;
			}
			std::cout << "\n";
		}
		std::cout << "Deseja inicializar um novo cliente? (s/n)\n";
		std::cin >> cliente;
	}
	return 0;
}

void Front::exibirMenu(){
	std::cout << "Bom dia, escolha uma das opções abaixo digitando o número em questão \n";
	std::cout << "1 - Listar produtos\n";
	std::cout << "2 - Adicionar compra a sacola\n";
	std::cout << "3 - Visualizar produtos na sacola\n";
	std::cout << "4 - Finalizar compras do cliente\n";
	//std::cout << "0 - Encerrar o programa\n";
}

void Front::listar(){
	for (auto i : estabelecimento.produtosDispo){
		std::cout << i.toString() << "\n";
	}
}

void Front::comprar(int codigo, Cliente &cliente){
	if (estabelecimento.venda(codigo, cliente)){
		std::cout << "Venda efetuada\n";
	} else {
		
		std::cout << "Não foi possivel efetuar a compra\n";
	}
}


void Front::listar(Cliente cliente){
	for (auto i : cliente.sacola){
		std::cout << i.toString() << "\n";
	}
}