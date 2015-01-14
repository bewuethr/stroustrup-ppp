// Chapter 23, exercise 12: read a text file and write it into a new file, which
// should be identical, except that all dates should be changed to ISO-format
// (yyyy-mm-dd) - based on the program from exercise 6

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdexcept>
#include<regex>
#include<iomanip>

using namespace std;

//------------------------------------------------------------------------------

// turn date matching pat1 into ISO format
string switch_date1(const string& md1, const string& md2, const string& y)
{
    int m_or_d1 = stoi(md1);
    int m_or_d2 = stoi(md2);
    ostringstream oss;
    oss << setfill('0');
    if (m_or_d1 > 12)
        oss << y << "-" << setw(2) << m_or_d2 << "-" << setw(2) << m_or_d1;
    else
        oss << y << "-" << setw(2) << m_or_d1 << "-" << setw(2) << m_or_d2;
    return oss.str();
}

//------------------------------------------------------------------------------

// takes string describing month, returns corresponding int
int mtoint(const string& s)
{
    if (s=="January") return 1;
    if (s=="February") return 2;
    if (s=="March") return 3;
    if (s=="April") return 4;
    if (s=="May") return 5;
    if (s=="June") return 6;
    if (s=="July") return 7;
    if (s=="August") return 8;
    if (s=="September") return 9;
    if (s=="October") return 10;
    if (s=="November") return 11;
    if (s== "December") return 12;
    throw runtime_error("Invalid month name");
}

//------------------------------------------------------------------------------

// turn date matching pat2 or pat3 into ISO format
string switch_date2(const string& md1, const string& md2, const string& y)
{
    ostringstream oss;
    oss << setfill('0');
    if (isdigit(md1[0]))
        oss << y << "-" << setw(2) << mtoint(md2) << "-" << setw(2) << stoi(md1);
    else
        oss << y << "-" << setw(2) << mtoint(md1) << "-" << setw(2) << stoi(md2);
    return oss.str();
}

//------------------------------------------------------------------------------

int main()
try {
    string ifname = "pics_and_txt/chapter23_ex12_in.txt";
    ifstream ifs(ifname);
    if (!ifs) throw runtime_error("Can't open " + ifname);
    string ofname = "pics_and_txt/chapter23_ex12_out.txt";
    ofstream ofs(ofname);
    if (!ofs) throw runtime_error("Can't open " + ofname);

    // Notices non-greedy quantifier *? to avoid capturing the first date digit
    // Dates with month or day first, separated by / or . or -
    regex pat1("^(.*?)(\\d\\d?)\\s*[-/\\.]\\s*(\\d\\d?)\\s*[-/\\.]\\s*(\\d{4})(.*)$");

    // Dates of format January 31, 2008
    regex pat2("^(.*?)(January|February|March|April|May|June|July|August|September|October|November|December)\\s+(\\d\\d?),\\s+(\\d{4})(.*)$");

    // Dates of format 31 January 2008
    regex pat3("^(.*?)(\\d\\d?)\\s+(January|February|March|April|May|June|July|August|September|October|November|December)\\s+(\\d{4})(.*)$");

    smatch matches;
    string line;
    while (getline(ifs,line)) {
        while (regex_match(line,matches,pat1)) {
            ostringstream oss;
            oss << matches[1] << switch_date1(matches[2],matches[3],matches[4])
                << matches[5];
            line = oss.str();
        }
        while (regex_match(line,matches,pat2) || regex_match(line,matches,pat3)) {
            ostringstream oss;
            oss << matches[1] << switch_date2(matches[2],matches[3],matches[4])
                << matches[5];
            line = oss.str();
        }
        ofs << line << '\n';
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
