#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

struct Diary
{
    Diary();
    ~Diary();

    std::vector<Message> messages;
    std::string path;
    std::string format;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
    void load();
    void updateConfig();
    std::vector<std::string> list(std::string formatSend);
    std::vector<Message*> search(const std::string& findString);
};
#endif
