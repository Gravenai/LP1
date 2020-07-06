#include "../include/App.h"

#include <iostream>
#include <string>

App::App() : diary()
{
    

}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {

        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if (argc == 2){
            list_messages();
        } else {
            list_messages(argv[2]);
        }
    } else if (action == "search") {
        if (argc == 3) {
            
            search(argv[2]);
        } else {
            return show_usage();
        }
    } else if (action == "interactive") {
        activeInteractive();
    } else {
        return show_usage();
    }

    return 0;
}

void App::activeInteractive (){
    int action = -1;
    std::string lixo;
    while (action != 0){
    show_menu();
    std::cin >> action;
    std::getline(std::cin, lixo);
    switch (action){
        case 1:
        list_messages();
        break;

        case 2:
        add();
        break;

        case 3:
        search();
        break;
    }
    }
}


void App::add()
{
    std::string message;
    std::cout << "Digite sua mensagem:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    list_messages(diary.format);
}

void App::list_messages(const std::string format){

    for (auto i : diary.list(format)){
        std::cout << i;
    }
}

void App::search(){
    std::string message;
    std::cout << "Digite sua mensagem:" << std::endl;
    std::getline(std::cin, message);

    search(message);
}

void App::search(const std::string message){

    for (auto i : diary.search(message)){
        std::cout << "- " << i->content << std::endl;
    }
}

void App::show_menu(){
    std::cout << "\n";
    std::cout << "Diário 1.0 \n";
    std::cout << "Selecione uma ação: \n";
    std::cout << "1) Listar mensagens \n";
    std::cout << "2) Adicionar nova mensagem \n";
    std::cout << "3) Buscar mensagem \n";
    std::cout << "\n";
    std::cout << "0) Finalizar \n";
    std::cout << "\n";
}

int App::show_usage()
{
    return 1;
}
