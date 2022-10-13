#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str) {
    string newStr {""};
   
    for(int i = str.length(); i >= 0; i--) {
       newStr+=str[i];
    }
    
    newStr == str ? return true : return false;
}

int main()
{
   string str{""};
   cin>>str;
   isPalindrome(str);
   return 0;
}
