
//
// This is example code from Chapter 14.3.5 "Pure virtual functions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class B {    // abstract base class
public:
    virtual void f() = 0;    // pure virtual function
    virtual void g() = 0;
};

//B b;    // error: B is abstract

//------------------------------------------------------------------------------

class D1 : public B { 
public:

    void f();
    void g();
};

D1 d1;        // ok

//------------------------------------------------------------------------------

class D2 : public B { 
public:

    void f();
    // no  g() 
};

//D2 d2;        // error: D2 is (still) abstract

//------------------------------------------------------------------------------

class D3 : public D2 { 
public:

    void g();
};

D3 d3;     // ok

//------------------------------------------------------------------------------
