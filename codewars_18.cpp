/**
 * https://www.codewars.com/kata/554b4ac871d6813a03000035/train/cpp
 * Highest and Lowest
 * cen be used 
 * 
*/

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;


std::string highAndLow(const std::string &numbers)
{
    stringstream ss;
    /* Storing the whole string into string stream */
    ss << numbers;
    int min = INT32_MAX;
    int max = INT32_MIN;
    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof())
    {
        /* extracting word by word from stream */
        ss >> temp;
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        {
            if (found > max)
                max = found;
            if (found < min)
                min = found;
        }
    }
    ss = std::stringstream();
    ss << max << " " << min;          
    return ss.str();
}

int main(int argc, char const *argv[])
{
     cout<< highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4"); 
    
    return 0;
}
