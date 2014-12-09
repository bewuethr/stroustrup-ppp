// Chapter 20, Exercise 06: write a find-and-replace operation for Documents
// based on §20.6.2.
//
// Behaviour (functional specification)
// - if search string is not found or empty, do nothing
// - if both search and replacement string contain no \n, replace in line
// - if search string contains \n and replacement string doesn't, merge with
//   next line
// - if search string doesn't contain \n and replacement string does, start new
//   line after inserting \n
// i.e., after search and replace, every line ends with \n, and \n is never not
// at the end of a line
//
// Implementation (technical specification)
// Get iterator pointing to the first character to be replaced using find_txt;
// if it equals end() of the Document, do nothing.
//
// Have an iterator point at the first character of the search term and the
// replace term each. Loop through both, placing the character from the replace
// term into the Document, where the find_txt iterator (which moves along)
// points at. If \n is encountered in the search string, append the next line to
// the current one. If \n is encountered in the replace string, move the rest of
// the current line to the beginning of the next line.
//
// If the search and replace strings have different lengths, finish the
// the replacement by moving only the iterator for the longer string, folllowing
// the same rules concerning \n.

// Exercise 08: define a function that counts the number of characters in a
// Document.

// Exercise 09: count words in a Document. Two versions, one with "whitespace-
// separated sequences of characters" as words and one with "sequence of con-
// secutive alphabetic characters" as words.

// Exercise 10: word count program where user can specifiy the set of whitespace
// characters

#include "../lib_files/std_lib_facilities.h"

typedef vector<char> Line;  // a line is a vector of characters

// keep track of line and character position within a line
class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    // start the iterator at line ll's character position pp:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        :ln(ll), pos(pp) { }

    list<Line>::iterator get_line() { return ln; }
    Line::iterator get_pos() { return pos; }

    char& operator*() { return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
        { return ln==other.ln && pos==other.pos; }
    bool operator!=(const Text_iterator& other) const
        { return !(*this==other); }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;                      // proceed to next character
    if (pos==(*ln).end()) {
        ++ln;                   // proceed to next line
        pos = (*ln).begin();    // bad if ln==line.end(); so make sure it isn't
    }
    return *this;
}

template<class Iter> bool match(Iter first, Iter last, const string& s)
{
    string::const_iterator si = s.begin();
    while (first!=last && si!=s.end()) {
        if (*first!=*si) return false;
        ++first;
        ++si;
    }
    return true;
}

template<class Iter, class T> Iter find(Iter first, Iter last, const T& val)
{
    Iter p = first;
    while (p != last) {
        if (*p==val) return p;
        ++p;
    }
    return p;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size()==0) return last;   // can't find an empty string
    char first_char = s[0];
    while (true) {
        Text_iterator p = ::find(first,last,first_char);
        if (p==last || match(p,last,s)) return p;
        first = ++p;    // look at the next character
    }
}

template<class Iter> void advance(Iter& p, int n)
{
    if (n>0) {
        while (n>0) { ++p; --n; }
    }
    else if (n<0) {
        while (n<0) { --p; ++n; }
    }
}

struct Document {
    list<Line> line;    // a document is a list of lines
    Document() { line.push_back(Line()); }

    Text_iterator begin()   // first character of first line
        { return Text_iterator(line.begin(),(*line.begin()).begin()); }
    Text_iterator end()     // one beyond the last character of the last line
    {
        list<Line>::iterator last = line.end();
        --last;             // we know that the document is not empty
        return Text_iterator(last,(*last).end());
    }

    Text_iterator erase(Text_iterator pos);
    Text_iterator insert(Text_iterator pos, const char& ch);
    void concat(Text_iterator& pos); // move next line to end of current line
    void break_ln(Text_iterator pos);   // move rest of line to beginning of next
    void find_replace(Text_iterator first, Text_iterator last,
        const string& find_str, const string& repl_str);
};

void erase_line(Document& d, int n)
{
    if (n<0 || d.line.size()-1<=n) return;
    list<Line>::iterator p = d.line.begin();
    advance(p,n);
    d.line.erase(p);
}

Text_iterator Document::erase(Text_iterator pos)
{
    list<Line>::iterator list_it = pos.get_line();
    Line::iterator line_it = pos.get_pos();
    line_it = (*list_it).erase(line_it);
    return Text_iterator(list_it,line_it);
}

Text_iterator Document::insert(Text_iterator pos, const char& ch)
{
    list<Line>::iterator list_it = pos.get_line();
    Line::iterator line_it = pos.get_pos();
    line_it = (*list_it).insert(line_it,ch);
    return Text_iterator(list_it,line_it);
}

// insert contents of next line to current line, erase next line
// pass-by-reference so pos can be reset after invalidating because of resizing
void Document::concat(Text_iterator& pos)
{
    list<Line>::iterator cur_line = pos.get_line();
    Line::iterator line_pos = pos.get_pos();
    Line::size_type index = line_pos - (*cur_line).begin();
    list<Line>::iterator nxt_line = cur_line;
    ++nxt_line;
    (*cur_line).insert((*cur_line).end(),(*nxt_line).begin(),(*nxt_line).end());

    pos = Text_iterator(cur_line,(*cur_line).begin() + index);  // reset iterator

    // find number of line to erase, erase it
    list<Line>::iterator list_it = begin().get_line();
    int line_ctr = 0;
    while (list_it!=nxt_line) {
        ++list_it;
        ++line_ctr;
    }
    erase_line(*this,line_ctr);
}

// move rest of line to beginning of next line
void Document::break_ln(Text_iterator pos)
{
    list<Line>::iterator cur_line = pos.get_line();
    list<Line>::iterator nxt_line = cur_line;
    ++nxt_line;
    (*nxt_line).insert((*nxt_line).begin(),pos.get_pos()+1,(*cur_line).end());
    (*cur_line).erase(pos.get_pos()+1,(*cur_line).end());
}

void Document::find_replace(Text_iterator first, Text_iterator last,
    const string& find_str, const string& repl_str)
{
    if (find_str=="") return;   // replace empty string - do nothing
    Text_iterator pos = find_txt(first,last,find_str);
    while (pos!=last) {
        string::const_iterator find_it = find_str.begin();
        string::const_iterator repl_it = repl_str.begin();
        while (find_it!=find_str.end() && repl_it!=repl_str.end()) {
            if (*find_it != *repl_it) {
                *pos = *repl_it;
                if (*find_it=='\n') {   // deleted '\n', append next line
                    concat(pos);
                }
                if (*repl_it=='\n') break_ln(pos);  // inserted '\n', add line break
            }
            ++pos;
            ++find_it;
            ++repl_it;
        }

        // delete characters from find string in case it was longer
        while (find_it != find_str.end()) {
            if (*pos=='\n') concat(pos);
            pos = erase(pos);
            ++find_it;
        }

        // insert characters from replace string in case it was longer
        while (repl_it != repl_str.end()) {
            pos = insert(pos,*repl_it);
            if (*repl_it=='\n') break_ln(pos);
            ++pos;
            ++repl_it;
        }

        pos = find_txt(pos,last,find_str);    // search next occurrence
    }
}

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while (is.get(ch)) {
        d.line.back().push_back(ch);    // add the character
        if (ch=='\n')
            d.line.push_back(Line());   // add another line
    }
    if (d.line.back().size()) d.line.push_back(Line()); // add final empty line
    return is;
}

void print(Document& d, Text_iterator p)
{
    for ( ; p!=d.end(); ++p) cout << *p;
    cout << "\n";
}

// exercise 8
int char_count(Document& d)
{
    Text_iterator iter = d.begin();
    int ctr = 0;
    while (iter != d.end()) {
        ++iter;
        ++ctr;
    }
    return ctr;
}

// count number of words in file
int file_word_count(const string& fname)
{
    ifstream ifs(fname.c_str());
    if (!ifs) error("can't open file ",fname);
    string s;
    int ctr = 0;
    while (ifs>>s) ++ctr;
    return ctr;
}

// exercise 9a: count whitespace-separated words. To take advantage of the
// fact that reading from an istream into a string is using whitespace to
// separate strings, first print document to file, then read from file using
// the >> operator
int word_count1(Document& d)
{
    // write Document to file
    Text_iterator p = d.begin();
    string fname = "pics_and_txt/chapter20_ex09_tmp.txt";
    ofstream ofs(fname.c_str());
    if (!ofs) error("can't open file ",fname);
    while (p!=d.end()) {
        ofs << *p;
        ++p;
    }
    ofs.close();

    int ctr = file_word_count(fname);

    // delete file and return value
    remove(fname.c_str());
    return ctr;
}

// exercise 9b: count words defined as "sequence of alphabetic characters"
// do the same as word_count1, but when printing the temp file, replace any
// non-alphabetic character with a space
int word_count2(Document& d)
{
    // write Document to file
    Text_iterator p = d.begin();
    string fname = "pics_and_txt/chapter20_ex09_tmp.txt";
    ofstream ofs(fname.c_str());
    if (!ofs) error("can't open file ",fname);
    while (p!=d.end()) {
        if (isalpha(*p)) ofs << *p;
        else ofs << ' ';
        ++p;
    }
    ofs.close();

    int ctr = file_word_count(fname);

    // delete file and return value
    remove(fname.c_str());
    return ctr;
}

// true if c is contained in white
bool is_whitespace(char c, const string& white)
{
    for (int i = 0; i<white.size(); ++i) {
        if (white[i]==c) return true;
    }
    return false;
}

// exercise 10: count whitespace-separated words, where whitespace is user
// defined (the user can add to the standard whitespace characters)
int word_count3(Document& d, const string& white)
{
        // write Document to file
    Text_iterator p = d.begin();
    string fname = "pics_and_txt/chapter20_ex09_tmp.txt";
    ofstream ofs(fname.c_str());
    if (!ofs) error("can't open file ",fname);
    while (p!=d.end()) {
        if (is_whitespace(*p,white))
            ofs << ' ';
        else
            ofs << *p;
        ++p;
    }
    ofs.close();

    int ctr = file_word_count(fname);

    // delete file and return value
    remove(fname.c_str());
    return ctr;
}

int main()
try {
    string ifname = "pics_and_txt/chapter20_ex06_in.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("can't open file ",ifname);
    Document my_doc;
    ifs >> my_doc;
    print(my_doc,my_doc.begin());

    cout << "Searching for non-existing string 'wrong':\n\n";
    string f_str = "wrong";
    Text_iterator p = find_txt(my_doc.begin(),my_doc.end(),f_str);
    if (p==my_doc.end())
        cout << "not found";
    else
        print(my_doc,p);

    cout << "\n\nSearching for 'Proin\\neget':\n\n";
    f_str = "Proin\neget";
    p = find_txt(my_doc.begin(),my_doc.end(),f_str);
    if (p==my_doc.end())
        cout << "not found";
    else
        print(my_doc,p);

    cout << "Replace 'dolor' with 'FRITZLI':\n\n";
    f_str = "dolor";
    string r_str = "FRITZLI";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace 'est\\nmollis' with 'XYZ\\nABCDEF' (same length, \\n in "
        << "same place):\n\n";
    f_str = "est\nmollis";
    r_str = "XYZ\nABCDEF";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace 'Morbi\\ndapibus' with 'MORBI DAPIBUS' (same length, \\n is "
        << "removed):\n\n";
    f_str = "Morbi\ndapibus";
    r_str = "MORBI DAPIBUS";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace 'turpis' with 'TU\\nPIS' (same length, \\n is added):\n\n";
    f_str = "turpis";
    r_str = "TU\nPIS";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace 'Proin\\neget' with 'ABC\\nDEF\\nGHI' (different length, "
        << "\\n in different places, extra \\n):\n\n";
    f_str = "Proin\neget";
    r_str = "ABC\nDEF\nGHI";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace complete third line plus word before and after with "
        << "\\nTHIRDLINE\\n:\n\n";
    f_str = "massa\nposuere lorem, sed placerat orci tortor quis leo.\nDonec ";
    r_str = "\nTHIRDLINE\n";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Replace 'et' with 'MARATHON' (multiple occurrences):\n\n";
    f_str = "et";
    r_str = "MARATHON";
    my_doc.find_replace(my_doc.begin(),my_doc.end(),f_str,r_str);
    print(my_doc,my_doc.begin());

    cout << "Number of characters in this document: "
        << char_count(my_doc) << "\n";

    cout << "Number of words (whitespace-separated) in this document: "
        << word_count1(my_doc) << "\n";

    cout << "Number of words (sequences of alphabetic characters) in this "
        << "document: " << word_count2(my_doc) << "\n";

    cout << "Number of words separated by whitespace or \".!'\" in this "
        << "document: " << word_count3(my_doc,".!'") << "\n";
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






