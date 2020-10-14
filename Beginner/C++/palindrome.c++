#include <iostream>
#include <string>

bool isPalindrome(std::string &str) {
    std::string newStr {""};
   
    for(int i = str.length(); i >= 0; i--) {
       newStr+=str[i];
    }
    
    newStr == str ? return true : return false;
}

int main()
{
   std::string str{""};
   std::cin>>str;
   isPalindrome(str);
   return 0;
}
