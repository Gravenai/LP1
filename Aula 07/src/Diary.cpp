#include "../include/Diary.h"

Diary::Diary(const std::string& filename) : messages_capacity(10),
messages_size(0), messages(nullptr)
{
	//this->filename = filename;
	messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message){
    // adicionar mensagem no array de mensagens
   	if (messages_size < messages_capacity){
	    Message *aux = new Message;
	    aux->content = message;
	    messages[messages_size] = *aux;
	    messages_size = messages_size + 1;
	}
}

void Diary::write()
{
    // gravar as mensagens no disco
}
