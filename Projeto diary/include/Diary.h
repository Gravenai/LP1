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
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    std::vector<Message> messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
    void load();
    void updateCapacity();
    std::vector<Message*> search(const std::string& findString);
};
#endif
