#include <iostream>
#include "Airplane.h"
using namespace std;

int main()
{
    cout << sizeof(Airplane) << endl;
    size_t const N = 100;
    Airplane* p[N];

    for(int i = 0; i < N; ++i)
    {
        p[i] = new Airplane;
    }

    p[1]->set(1000, 'A');
    p[5]->set(2000, 'B');
    p[9]->set(500000, 'C');


    for(int i = 0; i < 10; ++i)
    {
        cout << p[i] << endl;
    }

    for(int i = 0; i < 10; ++i)
    {
        delete p[i];
    }
    return 0;
}