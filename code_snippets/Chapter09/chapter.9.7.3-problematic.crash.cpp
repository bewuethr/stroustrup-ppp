
//
// This is example code from Chapter 9.7.3 "Default constructors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

// simple Date (use Month type):
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // check for valid date and initialize
    {
        // ...
    }

private:
    int   y;                    // year
    Month m;
    int   d;                    // day
};

//------------------------------------------------------------------------------


int main()
{
    //Date d1;                  // error: no initializer
    //Date d2(1998);            // error: too few arguments
    //Date d3(1,2,3,4);         // error: too many arguments
    //Date d4(1,"jan",2);       // error: wrong argument type
    Date d5(1,Date::jan,2);     // ok: use the three-argument constructor
    Date d6 = d5;               // ok: use the copy constructor

    {
        string s1;              // default value: the empty string ""
        vector<string> v1;      // default value: the empty vector; no elements
        vector<string> v2(10);  // vector of 10 default strings
    }

    {
        string s1 = string();   // default value: the empty string ""
        vector<string> v1 = vector<string>(); // default value:
        // the empty vector; no elements
        vector<string> v2(10,string());       // vector of 10 default strings
    }

    {
        //However, we prefer the equivalent and colloquial:
        string s1;              // default value: the empty string ""
        vector<string> v1;      // default value: the empty vector; no elements
        vector<string> v2(10);  // vector of 10 default strings
    }

    string s;
    s[2] = 'a';                 // oops: assignment to random address
    s = "hello";

    vector<string> v;
    cout << v[3];               // oops: reading from random address

    //Date d;
    //Date::Month m = d.month();// oops: copying random value

    string s1 = "";
    vector<string> v1(0);
    vector<string> v2(10,"");   // vector of 10 empty strings
}

//------------------------------------------------------------------------------
