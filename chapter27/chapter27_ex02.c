/* Chapter 27, exercise 2: complete the intrusive List example in 27.9 and test
    it using every function */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct List {
    struct Link* first;
    struct Link* last;
};

struct Link {
    struct Link* pre;
    struct Link* suc;
};

struct Name {
    struct Link lnk;    /* the Link required by List operations */
    char* p;            /* the name string */
};

struct Name* make_name(char* n)
{
    struct Name* p = (struct Name*)malloc(sizeof(struct Name));
    p->p = n;
    return p;
}

void init(struct List* lst) /* initialize lst to empty */
{
    assert(lst);
    lst->first = lst->last = 0;
}

struct List* create()   /* make a new empty list on free store */
{
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    init(lst);
    return lst;
}

void clear(struct List* lst) {  /* free all elements of lst */
    assert(lst);
    {
        struct Link* curr = lst->first;
        while (curr) {
            struct Link* next = curr->suc;
            free(curr);
            curr = next;
        }
        lst->first = lst->last = 0;
    }
}

void destroy(struct List* lst)  /* free all elements of lst; then free lst */
{
    assert(lst);
    clear(lst);
    free(lst);
}

void push_back(struct List* lst, struct Link* p)    /* add p at end of lst */
{
    assert(lst);
    {
        struct Link* last = lst->last;
        if (last) {
            last->suc = p;  /* add p after last */
            p->pre = last;
        }
        else {
            lst->first = p; /* p is the first element */
            p->pre = 0;
        }
        lst->last = p;
        p->suc = 0;
    }
}


void push_front(struct List* lst, struct Link* p)   /* add p at front of lst */
{
    assert(lst);
    {
        struct Link* first = lst->first;
        if (first) {
            first->pre = p; /* add p before first */
            p->suc = first;
        }
        else {
            lst->last = p;  /* p is the last element */
            p->suc = 0;
        }
        lst->first = p;
        p->pre = 0;
    }
}

/* insert q before p in lst: */
void insert(struct List* lst, struct Link* p, struct Link* q)
{
    assert(lst);
    if (q==0) return;   /* insert nothing */

    if (p == lst->first)    /* works also for empty list */
        push_front(lst,q);  /* q becomes new first element */
    else {
        q->suc = p;
        q->pre = p->pre;
        p->pre->suc = q;
        p->pre = q;
    }
}

/* remove p from lst; return a pointer to the link after p*/
struct Link* erase(struct List* lst, struct Link* p)
{
    assert(lst);
    if (p==0) return 0; /* OK to erase(0) */

    if (p == lst->first) {
        if (p->suc) {
            lst->first = p->suc;    /* the successor becomes first */
            p->suc->pre = 0;
            return p->suc;
        }
        else {
            lst->first = lst->last = 0; /* the list becomes empty */
            return 0;
        }
    }
    else if (p == lst->last) {
        if (p->pre) {
            lst->last = p->pre; /* the predecessor becomes last */
            p->pre->suc = 0;
            return 0;
        }
        else {
            lst->first = lst->last = 0; /* the list becomes empty */
            return 0;
        }
    }
    else {
        p->suc->pre = p->pre;
        p->pre->suc = p->suc;
        return p->suc;
    }
}

/* return link n "hops" before or after p: */
struct Link* advance(struct Link* p, int n)
{
    assert(p);
    if (n > 0) {
        while (n--)
            p = p->suc;
        return p;
    }
    else if (n < 0) {
        while (n++)
            p = p->pre;
        return p;
    }
    else return p;  /* n == 0 */
}

void print_lst(struct List* lst)
{
    int count = 0;
    struct Link* curr = lst->first;
    for (; curr!=0; curr = curr->suc) {
        ++count;
        printf("element %d: %s\n",count,((struct Name*)curr)->p);
    }
}

int main()
{
    struct List* names = create();

    printf("Pushing back three names:\n");
    push_back(names,(struct Link*)make_name("Norah"));
    push_back(names,(struct Link*)make_name("Annemarie"));
    push_back(names,(struct Link*)make_name("Kris"));
    print_lst(names);

    printf("\nErasing second name:\n");
    erase(names,advance(names->first,1));
    print_lst(names);

    printf("\nPushing front one name:\n");
    push_front(names,(struct Link*)make_name("Bjarne"));
    print_lst(names);

    printf("\nInsert names at front and before last element:\n");
    insert(names,names->first,(struct Link*)make_name("Herbert"));
    insert(names,names->last,(struct Link*)make_name("Scott"));
    print_lst(names);

    printf("\nErasing first element until list empty:\n");
    while (erase(names,names->first));
    print_lst(names);

    printf("\nInserting one element so we have something to destroy:\n");
    insert(names,names->first,(struct Link*)make_name("Andrei"));
    print_lst(names);

    printf("\nDestroying list\n");
    destroy(names);
}
