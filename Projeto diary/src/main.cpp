#include "../include/App.h"

int main(int argc, char* argv[]){

    App aplicativo("dados.md");
    return aplicativo.run(argc, argv);
}
