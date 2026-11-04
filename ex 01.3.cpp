#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
string s = "verification";
cout << "First 4: " << s.substr(0,4) << endl;
cout << "From 4: " << s.substr(4) << endl;
int c = s.compare("verify");
cout << "compare vs 'verify': " << (c<0 ? "<" : c>0 ? ">" : "==") << endl;
int freq[26] = {0};
for(char ch:s) if(isalpha((unsigned char)ch)) freq[(ch-'a')]++;
cout << "letter counts: ";
for(int i=0; i<26; i++) if(freq[i]) cout << char('a'+i) << ":" << freq[i] << " ";
cout << endl;
return 0;
}
/*
OUTPUT:
First 4: veri
From 4: fication
compare vs 'verify': <
letter counts: a:1 c:1 e:1 f:1 i:3 n:1 o:1 r:1 t:1 v:1
*/