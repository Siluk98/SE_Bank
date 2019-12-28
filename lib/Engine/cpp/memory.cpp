#include "../hpp/memory.hpp"
#include <iostream>

/*
void * operator new(size_t osize)
{
    Memory::allocate(osize);
    void * p = malloc(osize);
    //std::cout << "Alocation: " << osize << std::endl;
    return p;
}
*/

unsigned int Memory::allocated = sizeof(unsigned int);

void Memory::allocate(unsigned int mem)
{
    Memory::allocated += mem;
    //print();
}

void Memory::deallocate(unsigned int mem)
{
    Memory::allocated -= mem;
}

void Memory::print()
{
    std::cout << allocated << std::endl;
}
