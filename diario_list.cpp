#include <fstream>
#include <iostream>
#include <string>

void useMessage(std::string programName);

//int compareAction(std::string action);

int main(int argc, char *argv[]){

	// Erro: Apenas um argumento
	switch (argc){
	case 1:
		useMessage(argv[0]);
		return -1;
	break;
	case 2:{
		
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, porém só foi enviados dois argumentos
			std::ofstream outputFile("saida.txt", std::ios::app);
			if (!outputFile.is_open()){
				// Erro: Arquivo não existe
				std::cerr << "Arquivo não existente ou sem permissão! \n";
				return -1;
			}
			std::cout << "Insira uma messagem: ";
			std::string message;
			std::getline(std::cin, message);
			std::cout << "Mensagem adicionada! (" << message << ")\n";
			outputFile << message << "\n";
			return 0;

		} else if (aux.compare("list") == 0) {
			// Caso: Comando list está escrito certo
			std::ifstream readFile("saida.txt");
			if (!readFile.is_open()){
				// Erro: Arquivo não existe
				std::cerr << "Arquivo não existente ou sem permissão! \n";
				return -1;
			}
			std::string message;
			int lineCount = 0;
			while (!readFile.eof()) {
				std::getline(readFile, message);
				if (message.size() == 0){
					// Caso a linha que foi lida não possua conteudo
					continue;
				}	
				lineCount++;
				std::cout << lineCount << ":" << message << "\n";
			
			}
		}
		else {
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
			if (!outputFile.is_open()){
				// Erro: Arquivo não existe
				std::cerr << "Arquivo não existente ou sem permissão! \n";
				return -1;
			}
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
	std::cout << "Para usar " << programName << "\n"
	<< "Opções: \n" 
	<< programName << " add <mensagem>" << "\n"
	<< programName << " list" << "\n";
}

//int compareAction(std::string action){}