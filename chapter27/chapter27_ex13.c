/* Chapter 27, exercise 13: define an input operation that reads an arbitrarily
   long sequence of whitespace-terminated characters into a zero-terminated
   array of chars */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

char* get_word()
{   int max = 8;
    char* word = (char*)malloc(max);
    int count = 0;
    int x;
    while ((x=getchar())!=EOF && isgraph(x)) {
        if (count == max-1) {   /* double capacity */
            max += max;
            word = (char*)realloc(word,max);
            if (word==0) exit(EXIT_FAILURE);
        }
        word[count++] = x;
    }
    word[count] = 0;
    return word;
}

int main()
{
    while (1) {
        char* word = get_word();
        if (!strcmp(word,"quit")) break;
        printf("%s\n",word);
    }
}
