#ifndef MEMORY_HPP
#define MEMORY_HPP

class Memory
{
public:
    static void allocate(unsigned int);
    static void deallocate(unsigned int);
    static void print();
private:
    Memory();
    ~Memory();
    static unsigned int allocated;
};

#endif
