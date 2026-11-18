
#include <iostream>
using namespace std;

class Tracer
{
    int id;

public:
    Tracer(int i)
    {
        id = i;
        cout << "Tracer " << id << " created." << endl;
    }

    ~Tracer()
    {
        cout << "Tracer " << id << " destroyed." << endl;
    }
};

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        Tracer *t = new Tracer(i);

        cout << "Tracer " << i << " is being used." << endl;

        delete t;
    }

    cout << "All tracers destroyed." << endl;

    return 0;
}

/*
SAMPLE OUTPUT:

Tracer 1 created.
Tracer 1 is being used.
Tracer 1 destroyed.
Tracer 2 created.
Tracer 2 is being used.
Tracer 2 destroyed.
Tracer 3 created.
Tracer 3 is being used.
Tracer 3 destroyed.
Tracer 4 created.
Tracer 4 is being used.
Tracer 4 destroyed.
Tracer 5 created.
Tracer 5 is being used.
Tracer 5 destroyed.
All tracers destroyed.
*/
