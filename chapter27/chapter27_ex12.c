/* Chapter 27, exercise 12: implememnt a lookup table for C-style strings and
    ints. Supported operations:
    - find(struct Table*, const char*)
    - insert(struct Table*, const char*, int)
    - erase(struct Table*, const char*)
    Representation could be an array of struct pairs or a pair of arrays
    (const char*[] and int*). Also choose return types for the functions. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARR_SIZE 256

struct Table {
    const char* c_strings[ARR_SIZE];
    int values[ARR_SIZE];
    int ctr;    /* keep track of number of pairs */
};

struct Table* create_table()
{
    struct Table* tbl = (struct Table*)malloc(sizeof(struct Table));
    int i;
    for (i = 0; i<ARR_SIZE; ++i) {
        tbl->c_strings[i] = "";
        tbl->values[i] = 0;
    }
    tbl->ctr = 0;
    return tbl;
}

void destroy(struct Table* tbl)
{
    free(tbl);
}

/* return the value corresponding to s in t if found, -99999 if not found */
int find(struct Table* tbl, const char* str)
{
    int i;
    for (i = 0; i<tbl->ctr; ++i) {
        if (!strcmp(tbl->c_strings[i],str))
            return tbl->values[i];
    }
    return -99999;
}

/* insert the Pair(s,v) into t; if s is already in t, overwrite the value;
   return 0 if okay, -1 if not (e.g., array full) */
int insert(struct Table* tbl, const char* str, int val)
{
    if (tbl->ctr == ARR_SIZE)   /* table is full */
        return -1;
    tbl->c_strings[tbl->ctr] = str;
    tbl->values[tbl->ctr] = val;
    ++tbl->ctr;
    return 0;
}

/* remove pair containing s from t, return the corresponding value or -99999 if
   tbl does not contain str */
int erase(struct Table* tbl, const char* str)
{
    if (find(tbl,str) == -99999)
        return -99999;
    {
        int i;
        int val;
        for (i = 0; i<ARR_SIZE; ++i)
        {
            if (!strcmp(tbl->c_strings[i],str)) {
                val = tbl->values[i];
                break;
            }
        }
        for ( ; i<ARR_SIZE-1; ++i) {
            tbl->c_strings[i] = tbl->c_strings[i+1];
            tbl->values[i] = tbl->values[i+1];
        }
        --tbl->ctr;
        return val;
    }
}

void print_table(struct Table* tbl)
{
    int i;
    for (i = 0; i<tbl->ctr; ++i)
        printf("%s: %d\n",tbl->c_strings[i],tbl->values[i]);
}

int main()
{
    struct Table* tbl = create_table();
    insert(tbl,"value0",0);
    insert(tbl,"value1",1);
    insert(tbl,"value2",2);
    print_table(tbl);
    printf("Removing value1\n");
    {
        int val = erase(tbl,"value1");
        printf("value1 had value %d\n",val);
    }
    print_table(tbl);
    {
        int val = find(tbl,"value2");
        printf("value2 has value %d\n",val);
        val = find(tbl,"valuex");
        if (val == -99999)
            printf("can't find valuex\n");
        val = erase(tbl,"valuex");
        if (val == -99999)
            printf("can't erase valuex\n");
    }
    destroy(tbl);
}
