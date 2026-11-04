#include<iostream>
using namespace std;
class widget{
int id;
static int count;
public:
widget(){id=++count;cout<<"created W"<<id<<endl;}
~widget(){--count;cout<<"destroyed W"<<id<<endl;}
static int alive(){return count;}
};
int widget::count=0;
int main(){
widget a,b;
cout<<"Alive="<<widget::alive()<<endl;
{widget c;cout<<"Alive="<<widget::alive()<<endl;}
cout<<"Alive="<<widget::alive()<<endl;
return 0;
}
/*
OUTPUT:
created W1
created W2
Alive=2
created W3
Alive=3
destroyed W3
Alive=2
destroyed W2
destroyed W1
*/
