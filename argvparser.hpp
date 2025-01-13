#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H
#pragma once

#include <string>
#include <map>
#include <iostream>

class CommandLine {
public:
    CommandLine(int argc, char* argv[]) {
        // Parse the command line arguments into the map
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg[0] == '-') {
                std::string value;
                if (i + 1 < argc && argv[i + 1][0] != '-') {
                    value = argv[++i]; // If next argument is not another flag, it's the value
                }
                arguments_[arg] = value;
            }
        }
    }

    // Check if a command line argument exists
    bool exists(const std::string& arg) const {
        return arguments_.find(arg) != arguments_.end();
    }

    // Get the value of an argument (returns an empty string if not found)
    std::string value(const std::string& arg) const {
        auto it = arguments_.find(arg);
        return (it != arguments_.end()) ? it->second : "";
    }

    // Append a new argument with its value
    void append(const std::string& arg, const std::string& value = std::string()) {
        arguments_[arg] = value;
    }

    // Remove an argument
    void remove(const std::string& arg) {
        arguments_.erase(arg);
    }

private:
    std::map<std::string, std::string> arguments_;
};

#endif
