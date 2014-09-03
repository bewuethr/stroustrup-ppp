
//
// This is example code from Chapter 25.4.4 "Inheritance and containers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class T>
class Array_ref {
public:
    Array_ref(T* pp, int s) : p(pp), sz(s) { }

    template<class Q> 
    operator const Array_ref<const Q>()
    {
        // check implicit conversion of elements:
        sizeof(static_cast<Q>(*static_cast<T*>(0)));
        // cast Array_ref:
        return Array_ref<const Q>(reinterpret_cast<Q*>(p),sz);
    }

    T& operator[ ](int n) { return p[n]; }
    const T& operator[ ](int n) const { return p[n]; }

    bool assign(Array_ref a)
    {
        if (a.sz!=a) return false;
        for (int i=0; i<sz; ++i) { p[i]=a.p[i]; }
    }

    void reset(Array_ref a) { reset(a.p,a.sz); }
    void reset(T* pp, int s) { p=pp; sz=s; }

    int size() const { return sz; }

    // default copy operations:
    //    Array_ref doesn't own any resources
    //    Array_ref has reference semantics
private:
    T* p;
    int sz;
};

//------------------------------------------------------------------------------

template <class T> Array_ref<T> make_ref(T* pp, int s)
{
    return (pp) ? Array_ref<T>(pp,s) : Array_ref<T>(0,0);
}

//------------------------------------------------------------------------------

template <class T> Array_ref<T> make_ref(vector<T>& v)
{
    return (v.size()) ? Array_ref<T>(&v[0],v.size()) : Array_ref<T>(0,0);
}

//------------------------------------------------------------------------------

template <class T, int s> Array_ref<T> make_ref(T (&pp)[s])
{
    return Array_ref<T>(pp,s);
}

//------------------------------------------------------------------------------

class Point
{
public:
    Point(int x, int y);
};

//------------------------------------------------------------------------------

class Shape 
{
public:
    virtual void draw();
};

//------------------------------------------------------------------------------

class Circle : public Shape { /* ... */ };

//------------------------------------------------------------------------------

class Rectangle : public Shape 
{
public:
    Rectangle(const Point& p1, const Point& p2);
};

//------------------------------------------------------------------------------

class Polygon : public Shape {};

//------------------------------------------------------------------------------

void better2(const Array_ref<Shape*const> a)
{
    for (int  i = 0; i<a.size(); ++i) 
        if (a[i])
            a[i]->draw();
}

//------------------------------------------------------------------------------

void f(Shape* q, vector<Circle*>& s0)
{
    const int max = 25;
    Polygon* s1[10]; 
    Shape* s2[20];
    // initialize
    Shape* p1 = new Rectangle(Point(0,0),Point(10,20));
    better2(make_ref(s0));       // ok: converts to Array_ref<Shape*const>
    better2(make_ref(s1));       // ok: converts to Array_ref<Shape*const>
    better2(make_ref(s2));       // ok (no conversion needed)
    //better2(make_ref(p1,1));   // error
    //better2(make_ref(q,max));  // error
}

//------------------------------------------------------------------------------
