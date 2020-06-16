#include <iostream>
#include <string>

int main(int argc, char *argv[]){

	// Erro: Apenas um argumento
	if (argc == 1){
		std::cout << "Use: " << argv[0] << " add <mensagem>" << "\n";
		return -1;

	} else if (argc == 2){
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, porém só foi enviados dois argumentos
			std::cout << "Insira uma messagem: ";
			std::string message;
			std::getline(std::cin, message);
			std::cout << "Mensagem adicionada! (" << message << ")\n";
			return 0;

		} else {
			// Erro: Comando add está escrito errado
			std::cout << "Use: " << argv[0] << " add <mensagem>" << "\n";
			return -1;

		}
	} else if (argc == 3){
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, foi enviado três argumentos
			std::cout << "Mensagem adicionada! (" << argv[2] << ")\n";
			return 0;

		} else {
			// Erro: Comando add está escrito errado
			std::cout << "Use: " << argv[0] << " add <mensagem>" << "\n";
			return -1;

		}
	} else {
		// Erro: Mais de três argumentos
		std::cout << "Use: " << argv[0] << " add <mensagem>" << "\n";
		return -1;

	}
}