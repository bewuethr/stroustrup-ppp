/* Chapter 27, exercise 9: using only C facilities, including the C standard
    library, read a sequence of words from stdin and write them to stdout in
    lexicographical order. Use qsort() or insert the words into an ordered list
    as you read them. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WORD_LEN 256
#define ARR_LEN 128

void print(char* words[])
{
    while (*words)
        printf("%s\n",*words++);
}

char* get_word()
{
    char* word = (char*)malloc(WORD_LEN);
    char* word_ptr = word;
    int x;
    while ((x=getchar()) != EOF) {
        if (x=='\n') {
            *word_ptr = 0;
            break;
        }
        *word_ptr = x;
        ++word_ptr;
    }
    return word;
}

/* wrapper fro strcmp so it can be used with qsort */
int cmpstr(const void* a, const void* b)
{
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}

int main()
{
    char* words[ARR_LEN] = { 0 };
    int ctr = 0;
    char* word;
    while (strcmp(word = get_word(),"quit"))
        words[ctr++] = word;
    printf("\nSequence of words before sorting:\n");
    print(words);
    qsort(words,ctr,sizeof(char*),cmpstr);
    printf("\nSequence after sorting:\n");
    print(words);
}
