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

bool issue_found = false; 

// checks if next string is a conjunction
void conjunction()
{
    string s = sstr.get();
    bool valid = false;
    if (s=="and" || s=="or" || s=="but" || s==".") valid = true;
    if (!valid) issue_found = true;
    else if (s == ".") sstr.putback(s);
}

// checks if a string is a noun
bool noun()
{
    string s = sstr.get();
    if (s=="birds" || s=="fish" || s=="C++")
        return true;
    else {
		if (s == ".") sstr.putback(s);
		return false;
	}
}

// checks if a string is a verb
bool verb()
{
    string s = sstr.get();
    if (s=="rules" || s=="fly" || s=="swim")
        return true;
    else {
		if (s == ".") sstr.putback(s);
		return false;
	}
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
void sentence() 
{
	bool s = subject();
	bool v = verb();
	if (!s || !v) issue_found = true;
}

int main() 
{
	try {
		while (true) {
			sentence();
			conjunctions();
			string s = sstr.get();
			if (s == "." && issue_found == true) {
				cerr << "Not OK \n";
				issue_found = false; 
			}
			else if (s == "." && issue_found == false) cout << "OK \n";
			else sstr.putback(s);									
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
}
