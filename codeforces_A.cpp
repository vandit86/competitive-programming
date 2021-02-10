#include <iostream>
#include <string>
#define MAX 10
using namespace std;
 
int main(int argc, char const *argv[])
{
    int n ; 
    string s;
    s.reserve(256);
    char f,b;
    size_t len;    
    cin >> n ; 
    for (size_t i = 0; i < n; i++)
    {
        cin >> s; 
        len = s.length(); 
        if (len > MAX){
            b = s.back();
            f = s.front();
            s.clear();  
            s.push_back(f); 
            s.append(to_string(len-2)); 
            s.push_back(b); 
        }
        cout<<s<<endl; 
        s.clear(); 
    }
    return 0;
}
