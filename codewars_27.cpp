/**
 * https://www.codewars.com/kata/536a155256eb459b8700077e/train/cpp
 * Your objective is to complete a function createSpiral(N) that receives 
 * an integer N and returns an NxN two-dimensional array with numbers 1 through 
 * NxN represented as a clockwise spiral.
 * Return an empty array if N < 1 or N is not int / number
 * Examples:
 * N = 3 Output: [[1,2,3],[8,9,4],[7,6,5]]
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> create_spiral(int n)
{
    
    if (n < 1) return {};
    std::cout << "N " << n << std::endl; 
    std::vector <std::vector <int> > dataset (n, 
                                    std::vector<int>(n));
    
    int N = n, L = n-1, j = 0, i = 0, s = 1;
    bool row = false; 
  
    for (int num = 1; num <= n*n ; num++){
      
      if (row){      
        L --;  
        dataset[i][j] = num; 
        
        if (L == 0){
            L = N-1;
            s = s * (-1);
            row = false;
            j+=s; 
        }
        else { 
          i+=s;
        }
         
      }
      
      else {
        N --;
        dataset[i][j] = num; 
        
        if (N == 0){
          N = L; 
          row = true;
          i+=s; 
        }
        else {
          j+=s;  
        }
    
      }
    }
    
  for (auto i : dataset)
  {
      std::cout << std::endl;
      for (auto j : i)
      {
          std::cout << j << " ";
      }
  }
  return dataset; 
}


int main(int argc, char const *argv[])
{
    create_spiral(3); 
    return 0;
}
