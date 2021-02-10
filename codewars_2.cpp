/*

Implement a method that accepts 3 integer values a, b, c. 
The method should return true if a triangle can be built with the sides of 
given length and false in any other case.
(In this case, all triangles must have surface greater than 0 to be accepted)

solution : The triangle inequality states that the sum of the lengths of any 
two sides of a triangle must be greater than or equal to the length of the third side.
*/

namespace Triangle
{
  bool isTriangle(int a, int b, int c)
  {
    if (a <= 0 || b <=0 || c<= 0 ) return false; 
    if ((a+b) > c && (b+c)>a && (c+a)>b) return true;
    return false; 
  }
};