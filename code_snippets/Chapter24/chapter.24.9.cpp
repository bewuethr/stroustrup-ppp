
//
// This is example code from Chapter 24.9 "Complex numbers" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <complex>
#include <numeric>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

namespace my
{
    template<class Scalar> class complex {
        // a complex is a pair of scalar values, basically a coordinate pair
        Scalar re, im;
    public: 
        complex(const Scalar & r, const Scalar & i) :re(r), im(i) { }
        complex(const Scalar & r) :re(r),im(Scalar ()) { }
        complex() :re(Scalar ()), im(Scalar ()) { }

        Scalar real() { return re; }    // real part
        Scalar imag() { return im; }    // imaginary part

        // operators:  =  +=  -=  *=  /=
    };
}

//------------------------------------------------------------------------------

typedef complex<double> dcmplx;    // sometimes complex<double> gets verbose

//------------------------------------------------------------------------------

void f(dcmplx z, vector< complex<double> >& vc)
{
    dcmplx z2 = pow(z,2);
    dcmplx z3 = z2*9.0+vc[3];
    dcmplx  sum = accumulate(vc.begin(), vc.end(), dcmplx());
    // ...
    //if (z2<z3) // error: there is no < for complex numbers
}

//------------------------------------------------------------------------------

int main()
{
    dcmplx d[10] = {
        dcmplx(1,2), 
        dcmplx(2,3), 
        dcmplx(3,4), 
        dcmplx(4,5), 
        dcmplx(5,6), 
        dcmplx(6,7), 
        dcmplx(7,8), 
        dcmplx(8,9), 
        dcmplx(9,0), 
        dcmplx(0,1)
    };
    vector<dcmplx> v(d,d+10);
    f(d[0], v);
}

//------------------------------------------------------------------------------
