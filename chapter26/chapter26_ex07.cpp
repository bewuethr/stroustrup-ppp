// Chapter 26, exercise 7: test the "simple text editor" from Section 20.6

#include "chapter26_ex07_text_editor.h"
#include<iostream>
#include<fstream>
#include<exception>
#include<string>

using namespace std;
using namespace Text_ed;

//-----------------------------------------------------------------------------

void test_find(const string& findme, Document& d, int ctr)
{
    Text_iterator iter = find_text(d.begin(),d.end(),findme);
    if (iter != d.end()) {
        cout << ctr << " Found " << findme << ": ";
        for (int i = 0; i<15; ++i) {
            cout << *iter;
            ++iter;
            if (iter == d.end())
                break;
        }
    }
    cout << '\n';
}

//-----------------------------------------------------------------------------

int main()
try {
    Document d;
    string ifname = "pics_and_txt/chapter20_ex06_in.txt";
    ifstream ifs(ifname);
    if (!ifs) throw runtime_error("can't open " + ifname);

    // test input operator
    ifs >> d;

    // test print function
    print(d);

    // test erase line function with invalid line
    erase_line(d,20);
    cout << '\n';
    print(d);

    // test erase line function with last line
    erase_line(d,15);
    cout << '\n';
    print(d);

    // test erase line function with first line
    erase_line(d,0);
    cout << '\n';
    print(d);

    // test erase line function with line in the middle
    erase_line(d,5);
    cout << '\n';
    print(d);

    // test find_text with empty string
    string findme = "";
    Text_iterator iter = find_text(d.begin(),d.end(),findme);
    if (iter == d.end())
        cout << "\n1 Empty string: not found\n";

    // test find_text with string that does not exist in document
    findme = "notindoc";
    iter = find_text(d.begin(),d.end(),findme);
    if (iter == d.end())
        cout << "2 Inexisting string: not found\n";

    // test find_text with string occurring at the beginning of the document
    test_find("elit.",d,3);

    // test find_text with string occurring at end of the document
    test_find("risus.",d,4);

    // test find_text with string occurring at the beginning of a line
    test_find("quis",d,5);

    // test find_text with string occurring at the end of a line
    test_find("faucibus",d,6);

    // test find_text with string occurring in the middle of a line
    test_find("ornare",d,7);

    // test find_text with a string containing \n
    test_find("est\nMauris",d,8);
}
catch (exception& e) {
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "exception \n";
}

//------------------------------------------------------------------------------
