// https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/train/cpp

#include <iostream>
#include <string>

std::string duplicate_encoder(const std::string& word){
  size_t arr [256] = {0};
  std::string res;
  res.assign (word);  

     for (size_t i = 0; i < res.size(); i++)
    {
        char c = tolower (res[i]); 
        res[i] = c;
        arr[c] ++ ; 
    }
     
    for (size_t i = 0; i < res.size(); i++)
    {    
        if(arr[res[i]]>1){
            res[i] = ')';
        }
        else res[i] = '('; 
    }

  return res;
}

int main(int argc, char const *argv[])
{
    std::cout << duplicate_encoder ("testsdfsdfffsdfsdfsdf"); 
    return 0;
}
