#include "argvparser.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    CommandLine cmd(argc, argv);

    if (cmd.exists("-flag")) {
        std::cout << "Flag value: " << cmd.value("-flag") << std::endl;
    }

    cmd.append("-newarg", "newvalue");
    std::cout << "New argument value: " << cmd.value("-newarg") << std::endl;

    cmd.remove("-newarg");
}
