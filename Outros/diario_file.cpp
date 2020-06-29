#include <fstream>
#include <iostream>
#include <string>

void useMessage(std::string programName);

int main(int argc, char *argv[]){

	// Erro: Apenas um argumento
	switch (argc){
	case 1:
		useMessage(argv[0]);
		return -1;
	break;
	case 2:{
		std::ofstream outputFile("saida.txt", std::ios::app);
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, porém só foi enviados dois argumentos
			std::cout << "Insira uma messagem: ";
			std::string message;
			std::getline(std::cin, message);
			std::cout << "Mensagem adicionada! (" << message << ")\n";
			outputFile << message << "\n";
			return 0;

		} else {
			// Erro: Comando add está escrito errado
			useMessage(argv[0]);
			return -1;

		}
	}
	break;
	case 3:{
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, foi enviado três argumentos
			std::ofstream outputFile("saida.txt", std::ios::app);
			std::cout << "Mensagem adicionada! (" << argv[2] << ")\n";
			outputFile << argv[2] << "\n";
			return 0;

		} else {
			// Erro: Comando add está escrito errado
			useMessage(argv[0]);
			return -1;

		}
	break;
	}
	default:
		// Erro: Mais de três argumentos
		useMessage(argv[0]);
		return -1;

	}
}

void useMessage(std::string programName){
	std::cout << "Use: " << programName << " add <mensagem>" << "\n";
}