
//
// This is example code from Chapter 25.3.4 "Stack example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <stddef.h> // required for size_t

//------------------------------------------------------------------------------

template<int N>class Stack { // stack of N bytes
public:
    Stack();                 // make an N byte stack
    void* get(int n);        // allocate n bytes from the stack; 
                             // return 0 if no free space
    void free();             // return the last value returned by get() to the stack
    int available() const;   // number of available bytes
private:
    // space for char[N] and data to keep track of what is allocated
    // and what is not (e.g. a top of stack pointer)
};

//------------------------------------------------------------------------------

class Port;
class Buffer;

//------------------------------------------------------------------------------

class Connection
{
public:
    Connection(Port* in, Port* out, int* buf);
    void* operator new(size_t size, void* place);
};

//------------------------------------------------------------------------------

extern Port* incoming;
extern Port* outgoing;

//------------------------------------------------------------------------------

int main()
{
    Stack<50*1024> my_free_store; // 50K worth of storage to be used as a stack

    void* pv1 = my_free_store.get(1024);
    int* buffer = static_cast<int*>(pv1);  

    void* pv2 = my_free_store.get(sizeof(Connection));
    Connection* pconn = new(pv2) Connection(incoming,outgoing,buffer);
}

//------------------------------------------------------------------------------
