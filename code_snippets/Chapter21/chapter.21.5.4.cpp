
//
// This is example code from Chapter 21.5.4 "Generalizing inner_product()" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class In2, class T, class BinOp, class BinOp2 >
T inner_product(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
    while(first!=last) {
        init  = op(init, op2(*first, *first2));
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
        0.0,
        plus<double>(),
        multiplies<double>());

    cout << "DJI value " << dji_index << '\n';
}

//------------------------------------------------------------------------------
