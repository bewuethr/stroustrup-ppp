/* Chapter 27, exercise 6: change the intrusive List example from 27.9 without
    changing function user interfaces; allocate Links in an array of links and
    have the members first, last, pre and suc be ints (indices into the array)
    */

/* By now I'm pretty sure that this wasn't supposed to be solved like this, but
    rather using a pool of Links. */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_SIZE 100

struct Link {
    int pre;
    int suc;
    char* p;
};

struct Link* make_link(char* n)
{
    struct Link* p = (struct Link*)malloc(sizeof(struct Link));
    p->p = n;
    return p;
}

struct List {
    int first;
    int last;
    struct Link links[MAX_SIZE];
};

void init(struct List* lst) /* initialize lst to empty */
{
    assert(lst);
    lst->first = lst->last = -1;
}

struct List* create()   /* make a new empty list on free store */
{
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    init(lst);
    return lst;
}

void destroy(struct List* lst)  /* free all elements of lst; then free lst */
{
    assert(lst);
    free(lst);
}

void push_back(struct List* lst, struct Link* p)    /* add p at end of lst */
{
    assert(lst);
    if (lst->last == MAX_SIZE-1) {
        printf("Sorry, list is full!\n");
        return;
    }
    if (lst->first == -1) { /* p is first element of list */
        ++lst->first;
        p->pre = -1;
    }
    else {  /* there are already elements in the list */
        lst->links[lst->last].suc = lst->last + 1;
        p->pre = lst->last;
    }
    ++lst->last;
    p->suc = -1;
    lst->links[lst->last] = *p;
    free(p);
}

/* move elements in lst one to the right, starting with first_idx */
void shift_right(struct List* lst, int first_idx)
{
    int idx = lst->last;
    while (idx >= first_idx) {
        lst->links[idx+1] = lst->links[idx];
        ++lst->links[idx+1].pre;
        lst->links[idx+1].suc =
            lst->links[idx].suc==-1 ? -1 : lst->links[idx].suc+1;
        --idx;
    }
    ++lst->last;
}

void push_front(struct List* lst, struct Link* p)   /* add p at front of lst */
{
    assert(lst);
    if (lst->last == MAX_SIZE-1) {
        printf("Sorry, list is full!\n");
        return;
    }
    if (lst->first == -1)   /* list is empty at the moment*/
        push_back(lst,p);
    else {
        shift_right(lst,0); /* updates lst->last */
        p->pre = -1;
        p->suc = 1;
        lst->links[lst->first] = *p;
        free(p);
    }
}

/* insert q before p in lst: */
void insert(struct List* lst, struct Link* p, struct Link* q)
{
    assert(lst);
    if (q==0) return;   /* insert nothing */

    if (p == &lst->links[lst->first])    /* works also for empty list */
        push_front(lst,q);  /* q becomes new first element */
    else {
        shift_right(lst,lst->links[p->pre].suc);    /* updates lst->last */
        q->pre = p->pre;
        q->suc = p->pre + 2;
        lst->links[p->pre+1] = *q;
    }
}

/* move elements in lst one to the left, starting with idx */
void shift_left(struct List* lst, int idx)
{
    while (idx <= lst->last) {
        lst->links[idx-1] = lst->links[idx];
        --lst->links[idx-1].pre;
        lst->links[idx-1].suc = lst->links[idx].suc;
        ++idx;
    }
    --lst->last;
}

/* remove p from lst; return a pointer to the link after p*/
struct Link* erase(struct List* lst, struct Link* p)
{
    assert(lst);
    if (p==0) return 0; /* OK to erase(0) */

    if (p == &lst->links[lst->last]) {
        if (p == &lst->links[lst->first]) /* list becomes empty */
            lst->first = -1;
        else
            lst->links[p->pre].suc = -1;
        --lst->last;
        return &lst->links[lst->last+1];    /* one past the last! */
    }
    else {
        int idx = p->pre + 1;   /* to return afterwards */
        shift_left(lst,idx+1);  /* updates lst->last */
        return &lst->links[idx];
    }
}

/* return link n "hops" before or after p: */
struct Link* advance(struct List* lst, struct Link* p, int n)
{
    assert(lst);
    assert(p);
    int idx = p - &lst->links[lst->first];
    idx += n;
    return &lst->links[idx];
}

void print_lst(struct List* lst)
{
    for (int i = 0; i<=lst->last; ++i)
        printf("element %d: %s\n",i+1,lst->links[i].p);
}

int main()
{
    struct List* names = create();

    printf("Pushing back three names:\n");
    push_back(names,(struct Link*)make_link("Norah"));
    push_back(names,(struct Link*)make_link("Annemarie"));
    push_back(names,(struct Link*)make_link("Kris"));
    print_lst(names);

    printf("\nErasing second name:\n");
    erase(names,advance(names,&names->links[names->first],1));
    print_lst(names);

    printf("\nPushing front one name:\n");
    push_front(names,(struct Link*)make_link("Bjarne"));
    print_lst(names);

    printf("\nInsert names at front and before last element:\n");
    insert(names,&names->links[names->first],(struct Link*)make_link("Herbert"));
    insert(names,&names->links[names->last],(struct Link*)make_link("Scott"));
    print_lst(names);

    printf("\nErasing first element until list empty:\n");
    while (names->first != -1)
        erase(names,&names->links[names->first]);
    print_lst(names);

    printf("\nInserting one element so we have something to destroy:\n");
    insert(names,&names->links[names->first],(struct Link*)make_link("Andrei"));
    print_lst(names);

    printf("\nDestroying list\n");
    destroy(names);
}
