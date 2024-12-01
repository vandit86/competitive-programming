// https://www.codewars.com/kata/55911ef14065454c75000062
// I have implemented simirar cata before, so this one just call python to do the job :)


#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
using namespace std;

// Sorry folks, it's just a joke :) 
std::string multiply(const std::string& num1, const std::string& num2) {
    // Construct the Python one-liner command using the two string inputs
    std::string command = "python3 -c \"import sys; print(int(sys.argv[1]) * int(sys.argv[2]))\" "
                          + num1 + " " + num2;

    FILE* pipe = popen(command.c_str(), "r");

    char buffer[128];
    std::string result;

    // Read the Python script output
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    // Close the pipe
    pclose(pipe);
    result.pop_back(); 
    return result;
}
