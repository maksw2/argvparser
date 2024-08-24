#include "argument_handler.h"
#include <iostream>

int main(int argc, char* argv[]) {
    map<string, string> args;
    parseArguments(args, argc, argv);

    // Example usage
    if (checkArgumentExists(args, "-dev")) {
        cout << "Development mode enabled" << endl;
    }

    addArgument(args, "-newArg", "value");
    deleteArgument(args, "-newArg");

    if (checkArgumentExists(args, "-test")) {
        addArgument(args, "-test2");
    }

    string argsStr = argumentsToString(args);
    cout << argsStr << endl;

    return 0;
}