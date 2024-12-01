https://www.codewars.com/kata/5526fc09a1bbd946250002dc
int FindOutlier(std::vector<int> arr)
{
   auto isOdd = [](int number) {
        return number % 2 != 0;
    };
    
    int cnt = 0; 
    for (auto i = 0U; i < 3; i ++){
      if (isOdd(arr[i])) cnt ++; 
    }
     
    for (const auto& i : arr ){
      bool res = (cnt>1) ? isOdd(i) : !isOdd(i);   
      if (!res) return i; 
    }    
  return 0;
}
