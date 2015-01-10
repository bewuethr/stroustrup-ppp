// Chapter 23, exercise 5: for a large email message file (thousands of messa-
// ges), compare the time required when using a multimap as opposed to using
// an unordered_multimap

#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<fstream>
#include<iostream>
#include<regex>
#include<ctime>

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

struct Mail_file {  // a Mail_file holds all the lines from a file and simplifies
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
    Mail_file mfile("pics_and_txt/chapter23_ex05_in.txt");


    // build the multimap
    multimap<string,const Message*> sender;
    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s = find_from_addr(&m);
        if (s!="")
            sender.insert(make_pair(s,&m));
    }

    // build the unordered_multimap
    unordered_multimap<string,const Message*> sender_u;
    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s = find_from_addr(&m);
        if (s!="")
            sender_u.insert(make_pair(s,&m));
    }

    cout << "Enter sender: ";
    string sname;
    getline(cin,sname);

    // find subjects in multimap
    typedef multimap<string,const Message*>::const_iterator MCI;
    clock_t t1 = clock();
    if (t1==clock_t(-1)) {
        cerr << "clock() didn't work\n";
        exit(1);
    }
    pair<MCI,MCI> pp = sender.equal_range(sname);
    for (MCI p = pp.first; p!=pp.second; ++p)
        cout << find_subject(p->second) << '\n';
    clock_t t2 = clock();
    if (t2==clock_t(-1)) {
        cerr << "clock overflow\n";
        exit(1);
    }
    double t_multi = double(t2-t1)/CLOCKS_PER_SEC;;

    // find subjects in unordered_multimap
    typedef unordered_multimap<string,const Message*>::const_iterator UMCI;
    t1 = clock();
    if (t1==clock_t(-1)) {
        cerr << "clock() didn't work\n";
        exit(1);
    }
    pair<UMCI,UMCI> ppu = sender_u.equal_range(sname);
    for (UMCI p = ppu.first; p!=ppu.second; ++p)
        cout << find_subject(p->second) << '\n';
    t2 = clock();
    if (t2==clock_t(-1)) {
        cerr << "clock overflow\n";
        exit(1);
    }
    cout << "multimap:\t" << t_multi << '\n';
    cout << "unordered_multimap:\t" << double(t2-t1)/CLOCKS_PER_SEC << '\n';
}