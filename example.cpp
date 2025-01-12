#include "argvparser.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    CommandLine cmd(argc, argv);
    
    // Example usage
    if (cmd.exists("-dev")) {
        std::cout << "-dev exists" << std::endl;
    }

    cmd.append("-newArg", "value");
    cmd.remove("-newArg");

    if (cmd.exists("-test")) {
        std::cout << "-test exists" << std::endl;
        cmd.append("-test2");
        std::cout << "Appended -test2" << std::endl;
    }
    
    return 0;
}