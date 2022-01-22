/**
 * https://www.codewars.com/kata/52cf02cd825aef67070008fa/train/cpp
 * 3kyu
 * 
 * Instructions : 
 * Help the general decode secret enemy messages. 
 * some patterns exists 
 * 
 * 
 *      aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        bdhpF,82QsLirJejtNmzZKgnB3SwTyXG 
        ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLir

        bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
        dhpF,82QsLirJejtNmzZKgnB3SwTyXG 
        ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhp

        !@#$%^&*()_+-
        !@#$%^&*()_+-


        bdfhjlnprtvxzBDFHJLNPRTVXZ
        dhlptxBFJNRVZ37,aeimquyCGK
        hpxFNV3,emuCKS08bjrzHPX5 g

        Expected: equal to "Hello World!"
        Actual: "atC5kcOuKAr!"
 * 
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

struct Encoder
{
    static std::string encode (const std::string& p_what){
        
    }
};



struct Decoder {
	static std::string decode (const std::string& p_what) {  
    std::cout << (Encoder::encode ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n" ;
    std::cout << (Encoder::encode ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n" ;  
    std::cout << (Encoder::encode ("!@#$%^&*()_+-")) << "\n" ;
    std::string a, b, c;              
    for (const auto& w : std::string("abcdefghijklmnopqrstuvwxyz")) {
	    a += Encoder::encode (std::string(  "") + w)[0];
	    b += Encoder::encode (std::string( "_") + w)[1];
	    c += Encoder::encode (std::string("__") + w)[2];
    }
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";		  
    return p_what;
	}
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
