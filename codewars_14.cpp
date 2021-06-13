// https://www.codewars.com/kata/52e88b39ffb6ac53a400022e/train/cpp

#include <iostream>
#include <bitset>
#include <sstream>

using namespace std; 

std::string uint32_to_ip(uint32_t ip)
{
    stringstream os; 
    string binary = std::bitset<32>(ip).to_string(); //to binary
    ulong v0 = std::bitset<8>(binary).to_ulong();
    ulong v1 = std::bitset<8>(binary.substr(8,8)).to_ulong();
    ulong v2 = std::bitset<8>(binary.substr(16,8)).to_ulong();
    ulong v3 = std::bitset<8>(binary.substr(24,8)).to_ulong();

    os<<v0<<"."<<v1<<"."<<v2<<"."<<v3; 
    return os.str(); 
}


int main()
{
    std::string binary = uint32_to_ip(2149583361); //to binary "128.32.10.1"
    std::cout<<binary<<"\n";

    return 0;
}