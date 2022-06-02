#include <iostream>
#include "Airplane.h"
using namespace std;
Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;


unsigned long Airplane::getMiles(){return rep.miles;}

char Airplane::getType(){return rep.type;}

void Airplane::set(unsigned long m, char t)
{
    rep.miles = m;
    rep.type = t;
}


void* Airplane::operator new(size_t size)
{
    if(size != sizeof(Airplane))
        return ::operator new(size);

    Airplane* p = headOfFreeList;
    if(p)
        headOfFreeList = p->next;
    else
    {
        Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        cout << "调用一次 operator new" << endl;
        for(int i = 1; i < BLOCK_SIZE - 1; ++i)
        {
            newBlock[i].next = &newBlock[i + 1];  
        }
        newBlock[BLOCK_SIZE - 1].next = 0;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}


void Airplane::operator delete(void* deadObject, size_t size)
{
    if(deadObject == 0) return;
    if(size != sizeof(Airplane))
    {
        ::operator delete(deadObject);
        return;
    }

    Airplane* carcass = static_cast<Airplane*>(deadObject);

    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}



