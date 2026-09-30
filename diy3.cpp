#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    void setData(float r, float i)
    {
        real = r;
        imag = i;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c[3];

    c[0].setData(2, 3);
    c[1].setData(4, 5);
    c[2].setData(6, 7);

    cout << "Complex numbers:" << endl;

    c[0].display();
    c[1].display();
    c[2].display();

    return 0;
}
/*
OUTPUT:
Complex numbers:
2 + 3i
4 + 5i
6 + 7i
*/