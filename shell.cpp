#include <iostream>
#include <string>

bool REPL = 1;


int main()
{
    std::string command;

    while(REPL) {
        std::cout <<"$ ";
        std::cin >> command;

    }
    

    return 0;
}