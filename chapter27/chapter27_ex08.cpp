// Chapter 27, exercise 8: write out every character on your keyboard together
// with its integer value; then, write the characters out in the order deter-
// mined by their integer value

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void print(const string& s)
{
    for (int i = 0; i<s.size(); ++i)
        cout << '\'' << s[i] << "\': " << (int)unsigned char(s[i]) << '\n';
}

bool comp_char(char a, char b)
{
    return unsigned char(a) < unsigned char(b);
}

int main()
{
    string s = R"(°+"*ç%&/()=?`§1234567890'^¦@#¬|¢´~è!ü¨[]éà£öä${}><\;:_,.-)";
    s += "QWERTZUIOPASDFGHJKLYXCVBNMqwertzuiopasdfghjklyxcvbnm";
    print(s);
    sort(s.begin(),s.end(),comp_char);
    cout << "\nAnd sorted:\n";
    print(s);
}
