// https://www.codewars.com/kata/5667e8f4e3f572a8f2000039

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s){
    std::string res; 
    for (auto i = 0U; i < s.size(); i ++){
        res+=toupper(s[i]);
        for (auto j = 0U; j < i ; j ++){
            res+=tolower(s[i]); 
        }
        res+='-';  
    }
    res.pop_back(); 
    return res; 
}
