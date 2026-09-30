#include <iostream>
#include <string>
using namespace std;
int main(){
string s;
cout << "Enter a word:";
cin >> s;
cout << "Length: " << s.length() << endl;
cout << "Upper: ";
for(char c : s) cout << (char) toupper(c);
cout << endl;

bool pal = true;
for(size_t i=0, j=s.size()-1; i<j; ++i,--j){
if(tolower(s[i]) != tolower(s[j])) { pal=false; break; }
}
cout << s << (pal ? " is" : " is NOT") << " a palindrome" << endl;


size_t pos = s.find("an");
if(pos != string::npos) cout << "an found at index " << pos << endl;
else cout << "an not found\n";

return 0;
}
/*
OUTPUT:
Enter a word:banana
Length: 6
Upper: BANANA
banana is NOT a palindrome
an found at index 1
Enter a word:madam
Length: 5
Upper: MADAM
madam is a palindrome
an not found
*/