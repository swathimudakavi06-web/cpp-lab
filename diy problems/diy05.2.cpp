
#include <iostream>
using namespace std;

class Time
{
    int hh, mm;

public:
    void input()
    {
        cout << "Enter hours and minutes: ";
        cin >> hh >> mm;
    }

    void display()
    {
        if (hh < 10)
            cout << "0";

        cout << hh << ":";

        if (mm < 10)
            cout << "0";

        cout << mm << endl;
    }

    friend Time later(Time t1, Time t2);
};

Time later(Time t1, Time t2)
{
    int time1 = t1.hh * 60 + t1.mm;
    int time2 = t2.hh * 60 + t2.mm;

    if (time1 > time2)
        return t1;
    else
        return t2;
}

int main()
{
    Time t1, t2, result;

    cout << "Enter first time:" << endl;
    t1.input();

    cout << "Enter second time:" << endl;
    t2.input();

    result = later(t1, t2);

    cout << "\nLater time is: ";
    result.display();

    return 0;
}

/*
SAMPLE INPUT:

Enter first time:
10 30
Enter second time:
12 45

SAMPLE OUTPUT:

Later time is: 12:45
*/
