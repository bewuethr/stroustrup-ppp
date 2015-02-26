/*  Chapter 27, Try This: test cat(), find and remove performance error, add
    comments */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char* cat(const char* id, const char* addr)
{
    int len_id = strlen(id);        /* so it has to be calculated only once */
    int sz = len_id + strlen(addr) + 2; /* add extra space for terminating 0 */
    char* res = (char*) malloc(sz);
    strcpy(res,id);
    res[len_id] = '@';          /* and not len_id + 1 */
    strcpy(res+len_id+1,addr);  /* and not len_id + 2 */
    res[sz-1] = 0;              /* terminate string */
    return res;
}

int main()
{
    char* id = "scott.meyers";
    char* addr = "aristeia.com";
    char* s = cat(id,addr);
    printf("%s\n",s);
}