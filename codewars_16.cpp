// https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp

#include<iostream>
#include <string>

using namespace std; 

std::string sum_strings(const std::string& a, const std::string& b) { 
  
  string res = ""; 
  char flag = 0; // set if sum of two num > 9

  for (int i = a.size(), j = b.size(); i > 0 || j > 0 || flag; i--, j--)
  {
    char numA = (i>0)? a[i-1] : '0';
    char numB = (j>0)? b[j-1] : '0';
    char numC = (numA - '0') + (numB -'0') + flag; 
    if (numC > 9 ) {
      flag = 1 ;
      numC -=10;    
    }
    else {
      flag = 0 ; 
    }
    res.insert(0,1,numC+'0');    
  }
  return res;
}


int main(int argc, char const *argv[])
{
    cout<< sum_strings("99","2")<<endl; 
    return 0;
}

