// Chapter 19, exercise 12: File_handle class with a constructor that takes
// a string argument (the file name), opens the file in the constructor and
// closes it in the destructor

#include "../lib_files/std_lib_facilities.h"

//------------------------------------------------------------------------------

class File_handle {
    FILE* f;
    string fname;
public:
    File_handle(const string& fn, const string& m);
    ~File_handle();
    FILE* file() { return f;    }
};

//------------------------------------------------------------------------------

File_handle::File_handle(const string& fn, const string& m)
    : f(0), fname(fn)
{
    cout << "Opening file " << fname << "\n";
    f = fopen(fn.c_str(),m.c_str());
    if (!f) error("Problem opening ",fname);
}

//------------------------------------------------------------------------------

File_handle::~File_handle()
{
    cout << "Closing file " << fname << "\n";
    int i = fclose(f);
    if (i!=0) error("Problem with closing ",fname);
}

//------------------------------------------------------------------------------

void f(const string& s)
{
    File_handle fh(s,"w");
    cout << "Enter a string you would like to write into the file: ";
    string in;
    getline(cin,in);
    fwrite(in.c_str(),sizeof(char),in.size(),fh.file());
}

//------------------------------------------------------------------------------

int main()
try {
    f("pics_and_txt/chapter19_ex12_out.txt");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
