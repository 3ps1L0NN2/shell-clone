#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>

bool REPL = 1;
std::vector <std::string> BUILT_INS = {"echo", "exit", "type"};

void unknown_command(std::string command){
    std::cout << command <<" : command not found\n";
}

void type(std::string command)
{
    std::string cmd = command.substr(5);

    auto it = std::find(BUILT_INS.begin(), BUILT_INS.end(), cmd);
    bool found = (it != BUILT_INS.end());
    if (found) {
        std::cout << cmd << " is a shell builtin\n";
        return;
    }

    std::string path = std::getenv("PATH");     
    std::string dir = "";
    
    for(int i = 0; i <= path.size(); ++i){
        if (i==path.size() || path[i]==':') {
            if(!dir.empty()) {
                std::string full_path = dir + "/" +cmd;
                if (access(full_path.c_str(), X_OK) == 0) {
                    std::cout << cmd << " is " << full_path << std::endl;
                    return;
            }
        }

            dir = "";
        } else {
            dir += path[i];
        }
    }

    unknown_command(cmd);

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
            unknown_command(command);
    }
    

    return 0;
}