#include "../include/App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
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
        list_messages();
    } else if (action == "search") {
        if (argc == 3) {

            search(argv[2]);
        } else {
            return show_usage();
        }
    } else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
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
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

Message* App::search(const std::string findString){
    for (size_t i = 0; i < diary.messages_size; ++i) {
        Message* message = &(diary.messages[i]);
        int aux = -1;
        aux = message->content.find(findString);

        if (aux != -1){
            std::cout << "-" << message->content << std::endl;
            return message;
        }
    }
    return nullptr;
}

int App::show_usage()
{
    return 1;
}
