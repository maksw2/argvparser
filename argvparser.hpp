#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H
#pragma once

#include <string>
#include <map>
#include <optional>

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
	
	// Check if an argument exists and has a non-empty value
    bool exists_and_has_value(const std::string& arg) const {
        auto it = arguments_.find(arg);
        return it != arguments_.end() && !it->second.empty();
    }

    // Get the value of an argument (returns std::nullopt if not found)
    std::optional<std::string> value(const std::string& arg) const {
        auto it = arguments_.find(arg);
        if (it != arguments_.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    // Append a new argument with its value
    void append(const std::string& arg, const std::string& value = std::string()) {
        arguments_[arg] = value;
    }

    // Remove an argument
    void remove(const std::string& arg) {
        arguments_.erase(arg);
    }
	
	bool is_empty() const { 
    return arguments_.size() == 1; 
}

private:
    std::map<std::string, std::string> arguments_;
};

#endif
