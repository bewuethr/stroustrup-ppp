#ifndef TEXT_QUERY_GUARD
#define TEXT_QUERY_GUARD

#include "../lib_files/std_lib_facilities.h"
#include<map>

//------------------------------------------------------------------------------

namespace Text_query {;

// generate a map from a cleaned up text file (no interpunction etc.)
map<string,int> clean_txt(const string& fname);

// find the number of occurrences of a specific word
int num_of_occurrences(const string& word, const map<string,int>& clean_txt);

// find the first word with the highest number of occurences
string most_frequent(const map<string,int>& clean_txt);

// find the lexicographically first longest word
string longest(const map<string,int>& clean_txt);

// find the lexicographically first shortest word
string shortest(const map<string,int>& clean_txt);

// function object to find strings starting with specific character
class First_char {
    char ch;
public:
    First_char(char c) :ch(c) { }
    bool operator()(const pair<string,int>& p) const { return p.first[0] == ch; }
};

// find all words that start with char ch
vector<string> start_with(char ch, const map<string,int>& clean_txt);

// function object to find strings of a specific length
class Length {
    int n;
public:
    Length(int nn) :n(nn) { }
    bool operator()(const pair<string,int>& p) const { return p.first.size() == n; }
};

// find all words with length n
vector<string> has_length(int n, const map<string,int>& clean_txt);

} // Text_query

#endif