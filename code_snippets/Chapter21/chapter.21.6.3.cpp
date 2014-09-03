
//
// This is example code from Chapter 21.6.3 "Another map example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <map>
#include <string>
#include <utility>

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

double weighted_value(
    const pair<string,double>& a,
    const pair<string,double>& b
)    // extract values and multiply
{
    return a.second * b.second;
}

//------------------------------------------------------------------------------

int main()
{
    //First we make the (symbol,price) map:

    map<string,double> dow_price;
    // Dow Jones industrial index (symbol,price) , 03/31/ 2004
    // http://www.djindexes.com
    dow_price["MMM"] = 81.86; 
    dow_price ["AA"] = 34.69;
    dow_price ["MO"] = 54.45;
    // ...

    //The (symbol,weight) map:

    map<string,double> dow_weight;            // dow (symbol,weight)

    dow_weight.insert(make_pair("MMM", 5.8549));    
    dow_weight.insert(make_pair("AA",2.4808));
    dow_weight.insert(make_pair("MO",3.8940));    
    // ...

    //The (symbol,name) map:

    map<string,string> dow_name;              // dow (symbol,name)
    dow_name["MMM"] = "3M Co."; 
    dow_name["AA"]  = "Alcoa Inc.";
    dow_name["MO"]  = "Altria Group Inc.";
    // ...

    //Given those maps, we can conveniently extract all kinds of information. For example:

    double alcoa_price  = dow_price ["AA"];   // read values from a map
    double altria_price = dow_price ["MO"];

    if (dow_price.find("INTC") != dow_price.end()) // find an entry in a map
        cout << "Intel is in the Dow\n";

    typedef map<string,double>::const_iterator Dow_iterator;

    // write price for each company in the Dow index:
    for (Dow_iterator p = dow_price.begin(); p!=dow_price.end(); ++p) {
        const string& symbol = p->first;      // the "ticker" symbol
        cout << symbol << '\t'
             << p->second << '\t'
             << dow_name[symbol] << '\n';
    }

    double dji_index =
        inner_product(dow_price.begin(),      // all companies in the index
                      dow_price.end(),
                      dow_weight.begin(),     // their weights
                      0.0,                    // initial value
                      plus<double>(),         // add (as usual)
                      weighted_value);        // extract values and weights
                                              // and multiply
    cout << "DJI=" << dji_index << endl;
}

//------------------------------------------------------------------------------
