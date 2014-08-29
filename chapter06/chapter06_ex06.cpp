// Chapter 06, exercise 06: implement given grammar, check if sentence follows
// the grammar

/*
    Implements this grammar:

    Sentence:
        Subject Verb
        Sentence Conjunction Sentence

        Subject:
            Noun
            "the" Noun

        Conjunction:
            "and"
            "or"
            "but"

        Noun:
            "birds"
            "fish"
            "C++"

        Verb:
            "rules"
            "fly"
            "swim"

    and checks if an entered sentence is correct according to it or not.
*/

#include "../lib_files/std_lib_facilities.h"

// class to provide the next input string and the possibility to put back a string
class String_stream {
public:
    String_stream();
    string get();
    void putback(string s);
private:
    bool full;
    string buffer;
};

String_stream::String_stream()
    :full(false), buffer(" ") { }

void String_stream::putback(string s)
{
    if (full) error("putback() into a full buffer");
    buffer = s;
    full = true;
}

string String_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    string s = " ";
    cin >> s;
    return s;
}

String_stream sstr;

// checks if next string is a conjunction
bool conjunction()
{
    string s = sstr.get();
    if (s=="and" || s=="or" || s=="but")
        return true;
    else
        return false;
}

// checks if a string is a noun
bool noun()
{
    string s = sstr.get();
    if (s=="birds" || s=="fish" || s=="C++")
        return true;
    else
        return false;
}

// checks if a string is a verb
bool verb()
{
    string s = sstr.get();
    if (s=="rules" || s=="fly" || s=="swim")
        return true;
    else
        return false;
}

// handles subjects
bool subject()
{
    string s = sstr.get();
    if (s == "the")     // article before noun, check next string
        return noun();
    else {              // no article, put string back and check if noun
        sstr.putback(s);
        return noun();
    }
}

// handles sentences
bool sentence()
{
    return (subject() && verb());
}

int main()
try {
    bool is_ok = false;
    while (true) {
        is_ok = sentence(); // is set to true as long as sentence is correct
        if (!is_ok) cout << "Not OK\n";
        string s = sstr.get();
        if (s=="." && is_ok) cout << "OK\n";
        else {
            sstr.putback(s);
            is_ok = conjunction();
            if (!is_ok) cout << "Not OK\n";
        }
    }

}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
