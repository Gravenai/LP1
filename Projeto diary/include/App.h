#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diary.h"

#include <string>

struct App
{
    Diary diary;

    App();
    int run(int argc, char* argv[]);
    int show_usage();
    void show_menu();
    void activeInteractive();
    void add();
    void add(const std::string message);
    void list_messages();
    void list_messages(const std::string format);
    void search();
    void search(const std::string message);
};
#endif
