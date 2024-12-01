// https://www.codewars.com/kata/54b724efac3d5402db00065e

#include <string>
#include <sstream> // For std::istringstream


std::string decodeMorse(const std::string& morseCode) {
    std::string decoded {};
      
  // Find the first non-space character from the beginning
    size_t start = morseCode.find_first_not_of(' ');
    // Find the last non-space character from the end
    size_t end = morseCode.find_last_not_of(' ');

    // If the string is all spaces, return an empty string
    if (start == std::string::npos) {
        return "";
    }
    
  std::string code {morseCode.substr(start, end - start + 1)};
  auto pos = code.find("   "); 
  while ( pos != std::string::npos){
     code[++pos] = 'w';
     pos = code.find("   ");
  }
  
  std::istringstream stream(code);
  std::string word;
  
  // Read words one by one from the stream
  while (stream >> word) {
    auto w = (word == "w")? " ": MORSE_CODE[word];  
    decoded += w;  
  }
  
  return decoded;
}
