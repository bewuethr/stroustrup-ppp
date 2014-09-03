
//
// This is example code from Chapter 21.5.3 "Inner Product" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class In2, class T>
T inner_product(In first, In last, In2 first2, T init)
// note: this is the way we multiply two vectors (yielding a scalar)
{
    while(first!=last) {
        init  = init + (*first) * (*first2);    // multiply pairs of elements
        ++first;
        ++first2;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    // calculate the Dow Jones industrial index:
    vector<double> dow_price;        // share price for each company
    dow_price.push_back(81.86); 
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);
    // ...

    list<double> dow_weight;    // weight in index for each company
    dow_weight.push_back(5.8549);    
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);
    // ...

    double dji_index = inner_product(        // multiply (weight,value) pairs and add
        dow_price.begin(), dow_price.end(),
        dow_weight.begin(),
        0.0);

    cout << "DJI value " << dji_index << '\n';
}

//------------------------------------------------------------------------------
