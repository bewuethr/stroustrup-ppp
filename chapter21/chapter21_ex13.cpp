// Chapter 21, exercise 13: clean up a text file
// - replace punctuation with whitespace
// - put words into lower case
// - replace don't with do not etc.
// - remove plurals (for all words where you find "word" and "words")

#include "../lib_files/std_lib_facilities.h"
#include<map>

//------------------------------------------------------------------------------

map<string,int> clean_txt(const string& fname)
{
    ifstream ifs(fname);
    if (!ifs) error("Problem opening ",fname);
    ostringstream oss;

    // first pass: remove punctuation except single quotes, make everything
    // lower case
    char ch;
    while (ifs.get(ch)) {
        if (ispunct(ch) && ch!='\'')
            ch = ' ';
        oss << char(tolower(ch));
    }

    // second pass: word for word, replace single quotes with full words
    map<string,int> words;
    istringstream iss(oss.str());
    string w;
    while (iss >> w) {
        if (w == "can't")
            ++words["cannot"];
        else if (w == "shan't") {
            ++words["shall"];
            ++words["not"];
        }
        else if (w == "won't") {
            ++words["will"];
            ++words["not"];
        }
        else if (w=="'" || w.size()==2 && w[0]=='\'')  {
            // do nothing, don't add word
        }
        else if (w.size()>=3 && *(w.end()-2)=='\'') {
            switch (w.back()) {
            case 'd':
                ++words["would"];
                break;
            case 'm':
                ++words["am"];
                break;
            case 's':
                ++words["is"];
                break;
            case 't':   // special because 'n' has to be removed
                ++words["not"];
                ++words[w.substr(0,w.size()-3)];
                break;
            default:
                error("unexpected letter in ",w);
                break;
            }
            if (w.back()!='t')  // already been dealt with
                ++words[w.substr(0,w.size()-2)];
        }
        else if (w.size()>=4 && *(w.end()-3)=='\'') {
            switch (*(w.end()-2)) {
            case 'l':
                ++words["will"];
                break;
            case 'r':
                ++words["are"];
                break;
            case 'v':
                ++words["have"];
                break;
            default:
                error("unexpected letter in ",w);
                break;
            }
            ++words[w.substr(0,w.size()-3)];
        }
        else
            ++words[w];
    }

    //    typedef map<string,int>::iterator Iter;
    //for (Iter p = words.begin(); p!=words.end(); ++p)
    //    cout << setw(12) << left << p->first << ' ' << p->second << '\n';

    // third pass: for each word "abc", see if "abcs" exists. If yes, increase
    // count for "abc" by number of "abcs", erase "abcs"
    typedef map<string,int>::iterator Iter;
    for (Iter p = words.begin(); p!=words.end(); ++p) {
        Iter q = p;
        ++q;
        while (q != words.end()) {
            if (q->first==p->first+"s" && p->first.size()>1)
                q = words.erase(q); // increases q
            else
                ++q;
        }
    }

    return words;
}

//------------------------------------------------------------------------------

int main()
try {
    const string ifname = "pics_and_txt/chapter21_ex13_in3.txt";
    map<string,int> words = clean_txt(ifname);
    typedef map<string,int>::iterator Iter;
    for (Iter p = words.begin(); p!=words.end(); ++p)
        cout << setw(12) << left << p->first << ' ' << p->second << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}