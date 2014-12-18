// Chapter 21, Try This 4: get Dow Jones map example to work

#include "../lib_files/std_lib_facilities.h"
#include<map>
#include<numeric>

//------------------------------------------------------------------------------

double weighted_value(const pair<string,double>& a,
    const pair<string,double>& b)
{
    return a.second * b.second;
}

//------------------------------------------------------------------------------

int main()
try {
    map<string,double> dow_price;
    // Dow Jones Industrial index (symbol price);
    // for up-to-date quotes see www.djindexes.com
    dow_price["MMM"] = 160.60;
    dow_price["AXP"] = 90.44;
    dow_price["T"] = 32.67;
    dow_price["BA"] = 125.06;
    dow_price["CAT"] = 89.75;
    dow_price["CVX"] = 106.02;

    map<string,double> dow_weight;  // Dow (symbol, weight)
    dow_weight.insert(make_pair("MMM",5.94));
    dow_weight.insert(make_pair("AXP",3.35));
    dow_weight.insert(make_pair("T",1.21));
    dow_weight.insert(make_pair("BA",4.63));
    dow_weight.insert(make_pair("CAT",3.32));
    dow_weight.insert(make_pair("CVX",3.92));

    map<string,string> dow_name;    // Dow (symbol, name)
    dow_name["MMM"] = "3M Co.";
    dow_name["AXP"] = "American Express";
    dow_name["T"] = "AT&T";
    dow_name["BA"] = "Boeing";
    dow_name["CAT"] = "Caterpillar";
    dow_name["CVX"] = "Chevron";

    typedef map<string,double>::const_iterator Dow_iterator;

    // write price for each company in the Dow index:
    for (Dow_iterator p = dow_price.begin(); p!=dow_price.end(); ++p) {
        const string& symbol = p->first;    // the "ticker" symbol
        cout << symbol << '\t' << p->second << '\t' << dow_name[symbol] << '\n';
    }

    double dji_index =
        inner_product(dow_price.begin(),dow_price.end(),    // all companies
            dow_weight.begin(),     // their weights
            0.0,                    // initial value
            plus<double>(),         // add (as usual)
            weighted_value);        // and multiply

    cout << "DJI index is " << dji_index << "\n";
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

//------------------------------------------------------------------------------