// https://www.codewars.com/kata/55bf01e5a717a0d57e0000ec

int persistence(long long n){
   int res = 0; 
  auto str = std::to_string(n); 
  while (str.size()>1){
      unsigned long long tmp = 1; 
      for (auto& i : str){
        tmp*= i-'0'; 
      }
      str = std::to_string(tmp);
      ++res; 
  }
  return res; 
}
