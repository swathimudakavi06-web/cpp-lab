
#include <iostream>
using namespace std;

class Order
{
    static int nextID;
    int id;

public:
    Order()
    {
        id = nextID++;
    }

    void display()
    {
        cout << "Order ID: " << id << endl;
    }
};

int Order::nextID = 1001;

int main()
{
    Order o1;
    Order o2;
    Order o3;
    Order o4;

    o1.display();
    o2.display();
    o3.display();
    o4.display();

    return 0;
}

/*
SAMPLE OUTPUT:

Order ID: 1001
Order ID: 1002
Order ID: 1003
Order ID: 1004
*/
