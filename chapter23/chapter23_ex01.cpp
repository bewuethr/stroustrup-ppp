// Chapter 23, exercise 1: get the e-mail file example from 23.4 to run, test it
// with a larger file with messages that trigger errors such as containing two
// address lines, several messages with the same address and/or same subject,
// empty messages, files containing no ---- lines

// Exercise 2: add a multimap that holds subjects; let the program take an input
// string from the keyboard and print out every message with that string as its
// subject

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

//------------------------------------------------------------------------------

class Message { // a Message points to the first and the last lines of a message
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first(p1), last(p2) { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Message& m)
{
    for (Line_iter p = m.begin(); p!=m.end(); ++p)
        os << *p << '\n';
    return os;
}

//------------------------------------------------------------------------------

typedef vector<Message>::const_iterator Mess_iter;

//------------------------------------------------------------------------------

struct Mail_file {  // a Mail_file holds all the lines froma file and simplifies
                    // access to messages
    string name;            // file name
    vector<string> lines;   // the lines in order
    vector<Message> m;      // Messages in order;

    Mail_file(const string& n); // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

//------------------------------------------------------------------------------

// open file named "n"
// read the lines from "n" into "lines"
// find the messages in the lines and compose them in m
// for simplicity, assume every message is ended by a "----" line
Mail_file::Mail_file(const string& n) :name(n)
{
    ifstream in(n.c_str());
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1);    // terminate the program
    }

    string s;
    while (getline(in,s)) lines.push_back(s);   // build the vector of lines

    Line_iter first = lines.begin();    // build the vector of Messages
    for (Line_iter p = lines.begin(); p!=lines.end(); ++p) {
        if (*p == "----") {     // end of message
            m.push_back(Message(first,p));
            first = p+1;        // ---- no part of message
        }
    }
}

//------------------------------------------------------------------------------

// is p the first part of s?
int is_prefix(const string& s, const string& p)
{
    int n = p.size();
    if (string(s,0,n)==p) return n;
    return 0;
}

//------------------------------------------------------------------------------

// find the name of the sender in a Message;
// return true if found
// if found, place the sender's name in s
bool find_from_addr(const Message* m, string& s)
{
    for (Line_iter p = m->begin(); p!=m->end(); ++p)
        if (int n = is_prefix(*p,"From: ")) {
            s = string(*p,n);
            return true;
        }
    return false;
}

//------------------------------------------------------------------------------

// return the subject of the Message, if any, otherwise ""
string find_subject(const Message* m)
{
    for (Line_iter p = m->begin(); p!=m->end(); ++p)
        if (int n = is_prefix(*p,"Subject: ")) return string(*p,n);
    return "";
}

//------------------------------------------------------------------------------

int main()
{
    cout << "Enter name of mail file: ";
    string fname;
    cin >> fname;
    cin.ignore();   // get rid of \n
    Mail_file mfile(fname);

    // first gather messages from each sender together in a multimap
    multimap<string,const Message*> sender;
    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    // now iterate through the multimap and extract the subjects of John Doe's
    // messages
    cout << "Enter sender: ";
    string sname;
    getline(cin,sname);
    typedef multimap<string,const Message*>::const_iterator MCI;
    pair<MCI,MCI> pp = sender.equal_range(sname);
    for (MCI p = pp.first; p!=pp.second; ++p)
        cout << find_subject(p->second) << '\n';

    // gather messages by subject in a multimap
    multimap<string,const Message*> subjects;
    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s = find_subject(&m);
        if (s!="") subjects.insert(make_pair(s,&m));
    }

    // ask for subject
    cout << "Enter subject: ";
    string sub;
    getline(cin,sub);
    pp = subjects.equal_range(sub);
    for (MCI p = pp.first; p!=pp.second; ++p)
        cout << *p->second << '\n';
}