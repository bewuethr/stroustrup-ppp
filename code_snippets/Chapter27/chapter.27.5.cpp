
//
// This is example code from Chapter 27.5 "C-style strings" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <string>

using namespace std;

//------------------------------------------------------------------------------

char* p = "asdf";
char s[ ] = "asdf";

//------------------------------------------------------------------------------

int main()
{
    const char* s1 = "asdf";
    const char* s2 = "asdf";

    if (s1==s2) {        /* s1 and s2 points to the same array */
        /* (typically not what you want) */
    }

    if (strcmp(s1,s2)==0) {    /* s1 and s2 holds the same characters */

    }

    strcmp("dog","dog")==0;
    strcmp("ape","dodo")<0;    /* "ape" comes before "dodo" in a dictionary */
    strcmp("pig","cow")>0;     /* "pig" comes after "cow" in a dictionary */

    // We can finding the lengths of a C-style string using strlen():

    int lgt = strlen(s1);

    // We can copy one C-style string (incl. the terminating 0) into another:

    char s3[10];
    strcpy(s3,s2);    /* copy characters from s2 into s3 */

    string id = "name";
    string addr = "name.com";
    string s = id + '@' + addr;
}

//------------------------------------------------------------------------------

char* cat(const char* id, const char* addr)
{
    int sz = strlen(id)+strlen(addr)+2;
    char* res = (char*) malloc(sz);
    strcpy(res,id);
    res[strlen(id)+1] = '@';
    strcpy(res+strlen(id)+2,addr);
    res[sz-1]=0;
    return res;
}

//------------------------------------------------------------------------------
