#include "chapter21_ex14_tq.h"

//------------------------------------------------------------------------------

namespace Text_query {;

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

int num_of_occurrences(const string& word, const map<string,int>& clean_txt)
{
    if (clean_txt.find(word) != clean_txt.end())
        return clean_txt.at(word);
    else
        return 0;
}

//------------------------------------------------------------------------------

string most_frequent(const map<string,int>& clean_txt)
{
    string s;
    int max = 0;
    typedef map<string,int>::const_iterator Iter;
    for (Iter p = clean_txt.begin(); p!=clean_txt.end(); ++p) {
        if (p->second > max) {
            max = p->second;
            s = p->first;
        }
    }
    return s;
}

//------------------------------------------------------------------------------

string longest(const map<string,int>& clean_txt)
{
    string s;
    int l_max = 0;
    typedef map<string,int>::const_iterator Iter;
    for (Iter p = clean_txt.begin(); p!=clean_txt.end(); ++p) {
        if (p->first.length() > l_max) {
            l_max = p->first.length();
            s = p->first;
        }
    }
    return s;
}

//------------------------------------------------------------------------------

string shortest(const map<string,int>& clean_txt)
{
    string s;
    typedef map<string,int>::const_iterator Iter;
    Iter p = clean_txt.begin();
    s = p->first;
    int l_min = p->first.length();
    ++p;
    for (; p!=clean_txt.end(); ++p) {
        if (p->first.length() < l_min) {
            l_min = p->first.length();
            s = p->first;
        }
    }
    return s;
}

//------------------------------------------------------------------------------

vector<string> start_with(char ch, const map<string,int>& clean_txt)
{
    int count = count_if(clean_txt.begin(),clean_txt.end(),First_char(ch));
    vector<pair<string,int>> vp(count);
    copy_if(clean_txt.begin(),clean_txt.end(),vp.begin(),First_char(ch));
    vector<string> vs;
    for (int i = 0; i<vp.size(); ++i)
        vs.push_back(vp[i].first);
    return vs;
}

//------------------------------------------------------------------------------

vector<string> has_length(int n, const map<string,int>& clean_txt)
{
    int count = count_if(clean_txt.begin(),clean_txt.end(),Length(n));
    vector<pair<string,int>> vp(count);
    copy_if(clean_txt.begin(),clean_txt.end(),vp.begin(),Length(n));
    vector<string> vs;
    for (int i = 0; i<vp.size(); ++i)
        vs.push_back(vp[i].first);
    return vs;
}

//------------------------------------------------------------------------------

} // Text_query