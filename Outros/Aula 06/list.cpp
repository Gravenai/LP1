#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

static std::string fileName = "dados.md";

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { 
	std::string current_date = format_current_date("%d/%m/%Y");
	std::string completeDate = "# " + current_date;
	return completeDate; 
}

std::string get_current_time() {
	return format_current_date("%H:%M:%S"); }

void useMessage(std::string programName){
	std::cout << "Para usar " << programName << "\n"
	<< "Opções: \n" 
	<< programName << " add <mensagem>" << "\n"
	<< programName << " list" << "\n";
}

bool updateFile(std::string fileName){
	std::ifstream readFile(fileName,std::ios::ate);
	std::streampos size = readFile.tellg();
	char aux;
	std::string lastDay = "";

    for(int i=1;i<=size;i++){
        readFile.seekg(-i,std::ios::end);
        readFile.get(aux);

        // Se sobrar tempo, aprimore isso
        if (i == size){
        	std::getline(readFile, lastDay);
        	lastDay = "#" + lastDay;
        	break;
        }
        if (aux == '#'){
        	readFile.seekg(-i - 1,std::ios::end);
        	readFile.get(aux);
        	if (aux == '\n'){
        		std::getline(readFile, lastDay);
        		break;
        	}
        }
    }

    if (lastDay != get_current_date()){
    	std::ofstream outputFile(fileName, std::ios::app);
    	if (size != 0){
    		outputFile << "\n";
    	}
    	outputFile << get_current_date() << "\n";
    	outputFile.close();
    	return false;
    }
    return true;

}

int main(int argc, char *argv[]){

	// Erro: Apenas um argument
	switch (argc){
	case 1:
		useMessage(argv[0]);
		return -1;
	break;
	case 2:{
		
		std::string aux = argv[1];
		if (aux.compare("add") == 0){
			// Caso: Comando add está escrito certo, porém só foi enviados dois argumentos
			std::ofstream outputFile(fileName, std::ios::app);
			if (!outputFile.is_open()){
				// Erro: Arquivo não existe
				std::cerr << "Arquivo não existente ou sem permissão! \n";
				return -1;
			}
			std::cout << "Insira uma messagem: ";
			std::string message;
			std::getline(std::cin, message);
			updateFile(fileName);
			outputFile << "- " << get_current_time() << " " << message << "\n";
			std::cout << "Mensagem adicionada! (" << message << ")\n";
			return 0;

		} else if (aux.compare("list") == 0) {
			// Caso: Comando list está escrito certo
			std::ifstream readFile(fileName);
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
				if (message[0] == '#'){
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
			std::ofstream outputFile(fileName, std::ios::app);
			updateFile(fileName);

			if (!outputFile.is_open()){
				// Erro: Arquivo não existe
				std::cerr << "Arquivo não existente ou sem permissão! \n";
				return -1;
			}
			outputFile << "- " << get_current_time() << " " << argv[2] << "\n";
			std::cout << "Mensagem adicionada! (" << argv[2] << ")\n";
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
