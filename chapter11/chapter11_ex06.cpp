// Chapter 11, exercise 06: read text file, replace punctuation with
// whitespace, replace "don't" with "do not", "can't" with "cannot" etc.
// Leave hyphens within words intact
// Convert all characters to lower case
// Exercise 07: build dictionary from resulting file
// Use pics_and_txt/chapter11_ex06_in.txt for input

#include "../lib_files/std_lib_facilities.h"

//string oname;

// change string to lower case
void to_lowercase(string& s)
{
    if (s.size()==0) return;    // skipt empty line
    for (int i = 0; i<s.size(); ++i)
        s[i] = tolower(s[i]);
}

// remove punctuation except ' and -
void remove_punct(string& s)
{
    if (s.size()==0) return;    // skipt empty line
    for (int i = 0; i<s.size(); ++i)
        if (ispunct(s[i]) && s[i]!='\'' && s[i]!='-') s[i] = ' ';
}

// remove '-' when not within word or when '--'
void remove_hyphen(string& s)
{
    if (s.size()==0) return;    // skipt empty line
    // check for hyphen at beginning or end of line with space next to it
    if (s[0]=='-' && s[1]==' ') s[0] = ' ';
    if (s[s.size()-1]=='-' && s[s.size()-2]==' ') s[s.size()-1] = ' ';
    for (int i = 1; i<s.size()-1; ++i) {
        if (s[i]=='-' && s[i-1]==' ' && s[i+1]==' ') s[i] = ' ';
        if (s[i]=='-' && s[i+1]=='-') {
            s[i] = ' ';
            s[i+1] = ' ';
            ++i;
        }
    }
}

// replace "don't" with "do not", "can't" with "cannot" etc.
// removes extra spaces between words
void expand_aux(string& s)
{
    if (s.size()==0) return;    // skipt empty line
    istringstream is(s);
    string word;
    string s_exp;
    ostringstream os(s_exp);
    while (is>>word) {
        if (word=="can't") os << "cannot";
        else if (word.size() >= 3
                 && word[word.size()-3] == 'n'
                 && word[word.size()-2] == '\''
                 && word[word.size()-1] == 't') {
            for (int i = 0; i<word.size()-3; ++i)
                os << word[i];
            os << " not";
        }
        else os << word;
        os << ' ';
    }
    s = os.str();
}

// convert file
void convert_file(const string& iname, const string& oname)
{
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    string s;
    while (getline(ifs,s)) {
        to_lowercase(s);
        remove_punct(s);
        remove_hyphen(s);
        expand_aux(s);
        ofs << s << endl;
    }
}

// build dictionary file
void build_dict(const string& iname, const string& oname)
{
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ",iname);
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ",oname);

    vector<string> vs;
    string word;
    while (ifs>>word)
        vs.push_back(word);

    sort(vs.begin(),vs.end());
    for (int i = 0; i<vs.size(); ++i) {
        if (i==0 || vs[i]!=vs[i-1]) ofs << vs[i] << endl;
    }
}

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    cout << "Enter output file name: ";
    string oname;
    cin >> oname;
    convert_file(iname,oname);
    cout << "Enter name for dictionary file: ";
    string dname;
    cin >> dname;
    build_dict(oname,dname);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
