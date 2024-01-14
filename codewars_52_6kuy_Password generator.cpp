// https://www.codewars.com/kata/58ade2233c9736b01d0000b3

#include <string>
#include <iostream>
#include <random>
#include <ctime>

std::string password_gen() {
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string pwd; 
    int pwdSize = std::rand()%(20-6+1)+6; 
  while (true)
  { 
      if (pwd.size()>=20) pwd.clear(); 
      int idx = std::rand() % chars.length();
      pwd += chars[idx]; 
      if (any_of(pwd.begin(), pwd.end(), ::islower) &&
         any_of(pwd.begin(), pwd.end(), ::isupper) &&
         any_of(pwd.begin(), pwd.end(), ::isdigit) && 
         pwd.size() >= static_cast<size_t>(pwdSize)){
        break; 
      }
  } 
  return pwd;   
}
