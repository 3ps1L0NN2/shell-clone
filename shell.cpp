#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool REPL = 1;
std::vector <std::string> BUILT_INS = {"echo", "exit", "type"};

void type(std::string command)
{
    auto it = std::find(BUILT_INS.begin(), BUILT_INS.end(), command.substr(5));
    bool found = (it != BUILT_INS.end());
    if (found)
        std::cout << command.substr(5) << " is a shell builtin\n";
    else
        unknown_command(command.substr(5));
}

void unknown_command(std::string command){
    std::cout << command <<" : command not found\n";
}

int main()
{
    std::string command;

    while(REPL) {
        std::cout <<"$ ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command.substr(0,5) == "echo ") {
            std::cout << command.substr(5) << std::endl;
        } else if (command.substr(0,5) == "type ") {
            type(command);
        } else 
            std::cout << command <<" : command not found\n";
    }
    

    return 0;
}