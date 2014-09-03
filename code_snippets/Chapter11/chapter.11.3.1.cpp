
//
// This is example code from Chapter 11.3.1 "File open modes" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <fstream>

//------------------------------------------------------------------------------

using namespace std;

int main()
{
    const char* name  = "myfile0";
    const char* name1 = "myfile1";
    const char* name2 = "myfile2";

    ofstream of1(name1);    // defaults to ios_base::out
    ifstream if1(name2);    // defaults to ios_base::in

    ofstream ofs(name, ios_base::app);            // ofstreams are by default out
    fstream fs("myfile", ios_base::in|ios_base::out); // both in and out

    if (!fs)
    {
        // oops: we couldn't open that file that way
    }

    ifstream ifs("redungs");
    if (!ifs)
    {
        // error: can't open "readings" for reading
    }

    {
        ofstream ofs("no-such-file");        // create new file called no-such-file
        ofstream ifs("no-file-of-this-name");// error: ifs will be not be good() 
    }
}

//------------------------------------------------------------------------------
