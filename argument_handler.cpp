#include "argument_handler.h"
#include <iostream>

bool checkArgumentExists(const map<string, string>& args, const string& arg) {
    return args.count(arg) > 0;
}

string getArgumentValue(const map<string, string>& args, const string& arg) {
    if (!checkArgumentExists(args, arg)) {
        throw ArgumentHandlerException("Argument not found: " + arg);
    }
    return args.at(arg);
}

void addArgument(map<string, string>& args, const string& arg, const string& value) {
    if (arg.empty() || arg[0] != '-') {
        throw ArgumentHandlerException("Invalid argument format: " + arg);
    }
    args[arg] = value;
}

void deleteArgument(map<string, string>& args, const string& arg) {
    args.erase(arg);
}

void parseArguments(map<string, string>& args, int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        size_t pos = arg.find(' ');
        if (pos != string::npos) {
            args[arg.substr(0, pos)] = arg.substr(pos + 1);
        }
        else {
            args[arg] = "";
        }
    }
}

string argumentsToString(const map<string, string>& args) {
    string result;
    for (const auto& [arg, value] : args) {
        if (value == "") {
            result += arg + " ";
        }
        else {
            result += arg + " " + value + " ";
        }
    }
    return result.substr(0, result.size() - 1);
}