// Chapter 25, exercise 14: implement a simple vector that can hold at most N
// elements allocated from a pool; test it for N = 1000 and integer elements.

#include<iostream>

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

template<class T, int N> class Pool_vector {
public:
    Pool_vector();
    Pool_vector(int size);
    T& operator[](int n);
    void push_back(T elem);
    int size() { return sz; }
private:
    Pool<T,N> pool;
    T* ptr_to_dat[N];
    int sz;
};

//------------------------------------------------------------------------------

template<class T, int N> Pool_vector<T,N>::Pool_vector()
    :pool(), ptr_to_dat(), sz(0)
{
}

//------------------------------------------------------------------------------

template<class T, int N> Pool_vector<T,N>::Pool_vector(int n)
    :pool(), ptr_to_dat(), sz(n)
{
    if (n > N) {
        cout << "reducing size from " << n << " to " << N << 'n';
        sz = N;
    }
    for (int i = 0; i<sz; ++i) {
        ptr_to_dat[i] = pool.get();
    }
}

//------------------------------------------------------------------------------

template<class T, int N> T& Pool_vector<T,N>::operator[](int n)
{
    return *ptr_to_dat[n];
}

//------------------------------------------------------------------------------

template<class T, int N> void Pool_vector<T,N>::push_back(T elem)
{
    ptr_to_dat[sz] = pool.get();
    (*this)[sz] = elem;
    ++sz;
}

//------------------------------------------------------------------------------
    
int main()
{
    Pool_vector<int,10> pv(5);
    for (int i = 0; i<pv.size(); ++i)
        cout << pv[i] << '\n';
    pv[2] = 2;
    for (int i = 0; i<pv.size(); ++i)
        cout << pv[i] << '\n';

    Pool_vector<int,10> pv2;
    pv2.push_back(5);
    cout << "pv2.size(): " << pv2.size() << '\n';
    cout << "pv2[0]: " << pv2[0] << '\n';

    Pool_vector<int,1000> pv3;
    for (int i = 0; i<1000; ++i)
        pv3.push_back(i);
    cout << "pv3.size(): " << pv3.size() << '\n';
}
