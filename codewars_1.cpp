#include <vector>
/*
    Create a function that returns the sum of the two lowest positive
    numbers given an array of minimum 4 positive integers. 
    No floats or non-positive integers will be passed. 
 */
long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    unsigned long first, second= 0 ; 
    if (numbers[0] > numbers[1]){ first = numbers[1]; second = numbers[0];}
    else { first = numbers[0]; second = numbers[1]; }
    for (unsigned int i = 2; i<numbers.size(); i++){
        if (numbers[i] <= first ){
            second = first; 
            first = numbers[i]; 
        }
        else if (numbers[i] < second){ second = numbers[i]; }   
    }
    return first+second; 
}