#include "../include/Diary.h"

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        return;
    }

    Message m;
    m.content = message;

    messages[messages_size] = m;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}
