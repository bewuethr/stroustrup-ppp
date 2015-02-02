// Chapter 25, exercise 15: measure the time (average over three tries each) it
// takes to:
// - allocate 10,000 objects of random size in the [1000:0) byte range with new
// - deallocate the same objects with delete, in reverse order
// - deallocate the same objects with delete, in random order
// - allocate 10,000 objects of size 500 bytes from a pool
// - free the same objects
// - allocate 10,000 objects of random size in the [1000:0) byte range from a
//   stack
// - free the same objects in reverse order
//
// Requires increased stack size!

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

//------------------------------------------------------------------------------

template<class T, int N> class Pool {
public:
    Pool();                 // make pool of N Ts
    T* get();               // get a T fom the pool; return 0 if no free Ts
    void free(T* obj);      // return a T given out by get() to the pool
    int available() const;  // number of free Ts
private:
    T objects[N];
    bool is_used[N];
    int unused;
};

//------------------------------------------------------------------------------

template<class T, int N> Pool<T,N>::Pool() :objects(), is_used(), unused(N) { }

//------------------------------------------------------------------------------

template<class T, int N> T* Pool<T,N>::get()
{
    for (int i = 0; i<N; ++i)
        if (!is_used[i]) {
            is_used[i] = true;
            --unused;
            return &objects[i];
        }
    return 0;
}

//------------------------------------------------------------------------------

template<class T, int N> void Pool<T,N>::free(T* obj)
{
    *obj = T();   // make sure object is reset to default state
    ++unused;
    is_used[obj-objects] = false;
}

//------------------------------------------------------------------------------

template<class T, int N> int Pool<T,N>::available() const { return unused; }

//------------------------------------------------------------------------------

inline int randint(int max) { return rand()%max; }

//------------------------------------------------------------------------------

inline int randint(int min, int max) { return randint(max-min)+min; }

//------------------------------------------------------------------------------

struct Obj_500 {
    char data[500];
};

//------------------------------------------------------------------------------

template<int N> class Stack {
public:
    Stack();                // make an N-byte stack
    void* get(int n);       // allocate n bytes from the stack, return 0 if no
                            // free space
    void free();            // return the last value returned by get()
    int available() const;  // number of available bytes
private:
    char data[N];
    char* top;              // points to first free byte
    short obj_sizes[N/300]; // sizes of allocated objects
    int ctr;                // number of allocated objects
};

//------------------------------------------------------------------------------

template<int N> Stack<N>::Stack() :data(), top(&data[0]), obj_sizes(), ctr(0) { }

//------------------------------------------------------------------------------

template<int N> void* Stack<N>::get(int n)
{
    if (n > available()) return 0;
    void* p = top;
    top += n;
    obj_sizes[ctr] = n;
    ++ctr;
    return p;
}

//------------------------------------------------------------------------------

template<int N> void Stack<N>::free()
{
    --ctr;
    top -= obj_sizes[ctr];
    obj_sizes[ctr] = 0;
}

//------------------------------------------------------------------------------

template<int N> int Stack<N>::available() const
{
    return &data[N] - top;
}

//------------------------------------------------------------------------------

int main()
{
    const int reps = 10000;
    const int loops = 10;
    srand(time(0));

    vector<char*> data(reps);
    double t_alloc_new = 0;
    double t_dealloc_del = 0;
    for (int i = 0; i<loops; ++i) {
        clock_t t1 = clock();
        // allocate with new
        for (int j = 0; j<reps; ++j)
            data[j] = new char[randint(1000)+1];
        clock_t t2 = clock();
        t_alloc_new += double(t2-t1)/CLOCKS_PER_SEC;

        // deallocate with delete, reverse order
        t1 = clock();
        for (int j = reps-1; j>=0; --j)
            delete[] data[j];
        t2 = clock();
        t_dealloc_del += double(t2-t1)/CLOCKS_PER_SEC;
    }
    t_alloc_new /= loops;
    t_dealloc_del /= loops;
    cout << "Time to allocate with new: " << t_alloc_new*1000.0 << " ms\n";
    cout << "Time to deallocate with delete, reverse order: "
        << t_dealloc_del*1000.0 << " ms\n";

    double t_dealloc_del_rnd = 0;
    for (int i = 0; i<loops; ++i) {
        // allocate with new
        for (int j = 0; j<reps; ++j)
            data[j] = new char[randint(1000)+1];

        // deallocate with delete, random order
        random_shuffle(data.begin(),data.end());
        clock_t t1 = clock();
        for (int j = reps-1; j>=0; --j)
            delete[] data[j];
        clock_t t2 = clock();
        t_dealloc_del_rnd += double(t2-t1)/CLOCKS_PER_SEC;
    }
    t_dealloc_del_rnd /= loops;
    cout << "Time to deallocate with delete, random order: "
        << t_dealloc_del_rnd*1000.0 << " ms\n";

    Pool<Obj_500,reps> pool;
    Obj_500* pool_array[reps];
    
    double t_alloc_pool = 0;
    double t_free_pool = 0;
    for (int i = 0; i<loops; ++i) {
        clock_t t1 = clock();
        // allocate from pool
        for (int j = 0; j<reps; ++j)
            pool_array[j] = pool.get();
        clock_t t2 = clock();
        t_alloc_pool += double(t2-t1)/CLOCKS_PER_SEC;

        // free from pool
        t1 = clock();
        for (int j = reps-1; j>=0; --j)
            pool.free(pool_array[j]);
        t2 = clock();
        t_free_pool += double(t2-t1)/CLOCKS_PER_SEC;
    }
    t_alloc_pool /= loops;
    t_free_pool /= loops;
    cout << "Time to allocate from pool: " << t_alloc_pool*1000.0 << " ms\n";
    cout << "Time to free from pool: " << t_free_pool*1000.0 << " ms\n";

    Stack<6000000> stack;
    void* stack_array[reps];

    double t_alloc_stack = 0;
    double t_free_stack = 0;
    for (int i = 0; i<loops; ++i) {
        clock_t t1 = clock();
        // allocate from stack
        for (int j = 0; j<reps; ++j)
            stack_array[j] = stack.get(randint(1000)+1);
        clock_t t2 = clock();
        t_alloc_stack += double(t2-t1)/CLOCKS_PER_SEC;

        // free from stack
        t1 = clock();
        for (int j = 0; j<reps; ++j)
            stack.free();
        t2 = clock();
        t_free_stack += double(t2-t1)/CLOCKS_PER_SEC;
    }
    t_alloc_stack /= loops;
    t_free_stack /= loops;
    cout << "Time to allocate from stack: " << t_alloc_stack*1000.0 << " ms\n";
    cout << "Time to free from stack: " << t_free_stack*1000.0 << " ms\n";
}
