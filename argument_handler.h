#pragma once
#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H

#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class ArgumentHandlerException : public runtime_error {
public:
    explicit ArgumentHandlerException(const string& message) : runtime_error(message) {}
};

bool checkArgumentExists(const map<string, string>& args, const string& arg);
string getArgumentValue(const map<string, string>& args, const string& arg);
void addArgument(map<string, string>& args, const string& arg, const string& value = "");
void deleteArgument(map<string, string>& args, const string& arg);
void parseArguments(map<string, string>& args, int argc, char* argv[]);
string argumentsToString(const map<string, string>& args);

#endif