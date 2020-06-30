
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    std::string str1 = "ednaldo pereira";
    std::string str2 = "ednaasd";
    size_t aux = str1.find(str2);
    std::cout << aux;     

    return 0;
}
