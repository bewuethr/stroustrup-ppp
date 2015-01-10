// Chapter 23, exercise 4: modify email example to use a real email file

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
#include<regex>

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
// every message starts with ^From \d+@xxx.*$
Mail_file::Mail_file(const string& n) :name(n)
{
    ifstream in(n.c_str());
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1);    // terminate the program
    }

    string s;
    while (getline(in,s)) lines.push_back(s);   // build the vector of lines

    regex pat("^From \\d+@xxx.*$");     // matches first line of message
    smatch matches;
    Line_iter first = lines.begin();    // build the vector of Messages
    for (Line_iter p = lines.begin()+1; p!=lines.end(); ++p) {
        if (regex_match(*p,matches,pat)) {
            m.push_back(Message(first,p-1));
            first = p;
        }
        if (p+1==lines.end())
            m.push_back(Message(first,p));
    }
}

//------------------------------------------------------------------------------

// returns the rest of the first line in m that starts with s
string find_prefix(const Message* m, const string& s)
{
    regex pat("^" + s + "(.*)$");
    smatch matches;
        for (Line_iter p = m->begin(); p!=m->end(); ++p)
        if (regex_match(*p,matches,pat))
            return matches[1];
    return "";
}

//------------------------------------------------------------------------------

// return name of sender of Message, if any, otherwise ""
string find_from_addr(const Message* m)
{
    return find_prefix(m,"From: ");
}

//------------------------------------------------------------------------------

// return the subject of the Message, if any, otherwise ""
string find_subject(const Message* m)
{
    return find_prefix(m,"Subject: ");
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
        string s = find_from_addr(&m);
        if (s!="")
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
}