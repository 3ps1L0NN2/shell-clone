#include <iostream>
#include <string>

bool REPL = 1;




int main()
{
    std::string command;

    while(REPL) {
        std::cout <<"$ ";
        std::cin >> command;

        std::cout << command <<" : command not found\n";
    }
    

    return 0;
}