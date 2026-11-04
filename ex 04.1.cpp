#include<iostream>
using namespace std;
class Tracer{
int id;
public:
Tracer(int i):id(i){cout<<"construct #"<<id<<endl;}
~Tracer(){cout<<"destruct #"<<id<<endl;}
};
int main(){
cout <<"enter block\n";
{Tracer a(1),b(2);cout <<"...working..\n";}
cout<<"left block\n";
return 0;
}
/*
OUTPUT:
enter block
construct #1
construct #2
...working..
destruct #2
destruct #1
left block
*/
