// https://www.codewars.com/kata/5544c7a5cb454edb3c000047/train/cpp

#include <iostream>
using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

int Bouncingball::bouncingBall(double h, double b, double w)
{
    if (h > 0 && b > 0 && b < 1 && w < h)
    {
        int num = 1; // at least 1 time ball well be droped
        while (h >= w)
        {
            h *= b;
            if (h >= w)
                num += 2;
        }
        return num; 
    }
    else
        return -1;
}