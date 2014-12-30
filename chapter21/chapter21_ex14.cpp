// Chapter 21, exercise 14: using the output from exercise 13, write a program
// to answer questions such as "How many occurrences of 'ship' are there in a
// file?" "Which word occurs most frequently?" "Which is the longest word?"
// "Which is the shortest?" "List all words starting with 's'." "List all four-
// letter words."

#include "chapter21_ex14_tq.h"

//------------------------------------------------------------------------------

void print_menu()
{
    cout << "What would you like to do?\n"
        << "1 - Enter input file name\n"
        << "2 - Get number of occurrences of a word\n"
        << "3 - Get most frequent word\n"
        << "4 - Get longest word\n"
        << "5 - Get shortest word\n"
        << "6 - Get words starting with a specific letter\n"
        << "7 - Get words of a specific length\n"
        << "0 - Exit\n";
}

//------------------------------------------------------------------------------

string get_ifname()
{
    cout << "\nEnter input file name: ";
    string s;
    cin >> s;
    cout << '\n';
    return s;
}

//------------------------------------------------------------------------------

bool file_check(const string& fname)
{
    if (fname=="") {
        cout << "\nFile name is empty!\n\n";
        return false;
    }

    // test if file exists
    ifstream ifs(fname.c_str());
    if (!ifs) {
        cout << "\nFile " << fname << " doesn't exist!\n\n";
        return false;
    }

    return true;
}

//------------------------------------------------------------------------------

void get_n_occurrences(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    cout << "\nEnter word: ";
    string s;
    cin >> s;
    int n = Text_query::num_of_occurrences(s,clean_txt);
    cout << "\n\'" << s << "\' occurs " << n << " time" << (n==1?"":"s")
        << ".\n\n";
}

//------------------------------------------------------------------------------

void get_most_frequent(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    string s = Text_query::most_frequent(clean_txt);
    cout << "\nThe most frequent word is \'" << s << "\'.\n\n";
}

//------------------------------------------------------------------------------

void get_longest(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    string s = Text_query::longest(clean_txt);
    cout << "\nThe longest word is \'" << s << "\'.\n\n";
}

//------------------------------------------------------------------------------

void get_shortest(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    string s = Text_query::shortest(clean_txt);
    cout << "\nThe shortest word is \'" << s << "\'.\n\n";
}

//------------------------------------------------------------------------------

void get_start_with(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    cout << "\nEnter character: ";
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    vector<string> vs = Text_query::start_with(ch,clean_txt);
    cout << "\nWords starting with '" << ch << "':\n";
    for (int i = 0; i<vs.size(); ++i)
        cout << vs[i] << '\n';
    cout << '\n';
}

//------------------------------------------------------------------------------

void get_has_length(const map<string,int>& clean_txt)
{
    if (clean_txt.size() == 0) {
        cout << "\nNo text loaded!\n\n";
        return;
    }
    cout << "\nEnter number of characters: ";
    int n;
    cin >> n;
    if (!cin) {
        cout << "\nPlease enter a number\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return;
    }
    vector<string> vs = Text_query::has_length(n,clean_txt);
    cout << "\nWords with " << n << " characters:\n";
    for (int i = 0; i<vs.size(); ++i)
        cout << vs[i] << '\n';
    cout << '\n';
}

//------------------------------------------------------------------------------

int main()
try {
    string ifname;
    map<string,int> words;

    bool keep_running = true;
    while (keep_running) {
        print_menu();
        int n;
        cin >> n;
        if (!cin) {
            cout << "\nPlease enter a number\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        switch (n) {
        case 0:         // Exit
            keep_running = false;
            break;
        case 1:         // Get input file name, load cleaned text
            ifname = get_ifname();
            if (file_check(ifname))
                words = Text_query::clean_txt(ifname);
            break;
        case 2:         // Get number of occurrences of a word
            get_n_occurrences(words);
            break;
        case 3:         // Get most frequent word
            get_most_frequent(words);
            break;
        case 4:         // Get longest word
            get_longest(words);
            break;
        case 5:         // Get shortest word
            get_shortest(words);
            break;
        case 6:         // Get words starting with a specific letter
            get_start_with(words);
            break;
        case 7:         // Get words of a specific length
            get_has_length(words);
            break;
        default:
            cout << "\nEnter a number between 1 and 7\n\n";
            break;
        }

    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}