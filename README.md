# A simple crossplatform C++ launch arguments parser
Every argument passed has to start with `-` and *can* contatin a value.  
Example:
```
example.exe -argument value
```
The `value` is stored as an `std::string`, so it can be anything.  
You can have multiple arguments, but only one value per argument.  
The value cannot start with a `-`.