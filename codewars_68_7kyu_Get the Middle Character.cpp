// https://www.codewars.com/kata/56747fd5cb988479af000028

std::string get_middle(std::string input) 
{
  std::string res {input[input.length()/2]};
  return res = (input.length()%2==0)? input[input.length()/2-1] + res: res; 
}
