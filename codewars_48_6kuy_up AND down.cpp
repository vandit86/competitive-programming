// https://www.codewars.com/kata/56cac350145912e68b0006f0

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std; 

class UpAndDown
{
public:
    static std::string arrange(const std::string &strng);
};


// std::transform(str.begin(), str.end(), str.begin(), ::toupper);
//length s(0) <= length s(1) >= length s(2) <= length s(3) >= length (s4) <= length (s5

std::string UpAndDown::arrange(const std::string &str){
    stringstream iss (str); 
    stringstream oss{}; 
    string word {}; 
    vector<string> words {}; 

    while (iss>>word){
        words.push_back(word); 
    }
    if (words.size() == 0) return str; 

    for (auto i = 1; i < words.size(); i ++){
        if ( ( i%2  && words.at(i).size() < words.at(i-1).size()) || 
             !(i%2) && words.at(i).size() > words.at(i-1).size()){
                swap (words.at(i), words.at(i-1)); 
             }
    }

    for (auto i = 0; i < words.size(); i ++){
        if (i%2) {
            std::transform(words.at(i).begin(), words.at(i).end(), words.at(i).begin(), ::toupper);
        }
        else {
            std::transform(words.at(i).begin(), words.at(i).end(), words.at(i).begin(), ::tolower);
        }
        oss << words.at(i) << " "; 
    }

    auto res = oss.str(); 
    res.pop_back();
    return res;    
}
