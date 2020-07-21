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
	std::string codigo;
	
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
					std::cout << "Digite o nome de um produto: \n";
					getline(std::cin, codigo);
					getline(std::cin, codigo);
					comprar(codigo, novoCliente);
					
				break;
				case 3:
					listar(novoCliente);
				break;
				case 4:
					novoCliente.quantClientes++;
				break;
				case 5:
					listarFornecimento();
				break;
				case 6:
					std::cout << "Digite o nome do produto: \n";
					std::string nome;
					getline(std::cin, nome);
					getline(std::cin, nome);

					std::cout << "Digite a quantidade: \n";
					size_t quant;
					std::cin >> quant;
					reabastecerEstoque(quant, nome);
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
	std::cout << "5 - Visualizar produtos do fornecedor\n";
	std::cout << "6 - Adicionar produtos do fornecedor\n";
	//std::cout << "0 - Encerrar o programa\n";
}

void Front::listar(){
	for (int i = 0; i <= estabelecimento.produtosDispo.lastIndex; i++){
		std::cout << estabelecimento.produtosDispo.getElementIndex(i).toString() << "\n";
	}
}

void Front::comprar(std::string codigo, Cliente &cliente){

	if (estabelecimento.venda(codigo, cliente)){
		std::cout << "Venda efetuada\n";
	} else {
		
		std::cout << "Não foi possivel efetuar a compra\n";
	}
}


void Front::listar(Cliente &cliente){
	for (int i = 0; i <= cliente.sacola.lastIndex; i++){
		std::cout << cliente.sacola.getElementIndex(i).toString() << "\n";
	}
}

void Front::listarFornecimento(){
	VectorSup<Produto> aux = estabelecimento.listarFornecimento();
	for (int i = 0; i <= aux.lastIndex; i++){
		std::cout << aux.getElementIndex(i).toStringResumed() << "\n";
	}
	
}

void Front::reabastecerEstoque(size_t quant, std::string nome){
	if (estabelecimento.reabastecer(quant, nome)){
		std::cout << "Os produtos foram adicionados ao estoque";
	} else {
		std::cout << "Ocorreu um erro";
	}
}