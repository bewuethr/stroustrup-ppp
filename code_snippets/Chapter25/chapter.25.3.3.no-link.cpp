
//
// This is example code from Chapter 25.3.3 "Pool Example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class T, int N> 
class Pool                 // Pool of N objects of type T
{
public:
    Pool();                // make pool of N Ts
    T* get();              // get a T from the pool; return 0 if no free Ts
    void free(T*);         // return a T given out by get() to the pool
    int available() const; // number of free Ts
private:
    // space for T[N] and data to keep track of which Ts are allocated
    // and which are  not (e.g. a list of free objects)
};

//------------------------------------------------------------------------------

class Small_buffer;
class Status_indicator;

//------------------------------------------------------------------------------

int main()
{
    Pool<Small_buffer,10> sb_pool;
    Pool<Status_indicator,200> indicator_pool;

    Small_buffer* p = sb_pool.get();
    // ...
    sb_pool.free(p);
}

//------------------------------------------------------------------------------
