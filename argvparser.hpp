#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H
#pragma once

#include <string>
#include <map>

class CommandLine {
private:
    std::map<std::string, std::string> args;
public:
    CommandLine(int argc, char* argv[]) {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            size_t pos = arg.find(' ');
            if (pos != std::string::npos) {
                args[arg.substr(0, pos)] = arg.substr(pos + 1);
            }
            else {
                args[arg] = "";
            }
        }
    }
    bool exists(const std::string& ask) {
        return args.count(ask) > 0;
    }
    bool append(const std::string& argument, const std::string& value = std::string()) {
        if (argument.empty() || argument[0] != '-') {
            return false;
        }
        args[argument] = value;
        return true;
    }
    void remove(const std::string& argument) {
        args.erase(argument);
    }
};

#endif