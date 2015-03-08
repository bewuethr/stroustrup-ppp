/* Chapter 27, exercise 3: "pretty up" the intrusive List example from 27.9 */

#include<stdio.h>
#include<stdlib.h>

#define ERROR_PTR (struct Link*)0xDEADBEEF

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

/* initialize lst to empty; return 0 if okay, -1 if not */
int init(struct List* lst)
{
    if (lst==0) return -1;
    lst->first = lst->last = 0;
    return 0;
}

struct List* create()   /* make a new empty list on free store */
{
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    init(lst);
    return lst;
}

/* free all elements of lst; return 0 if okay, -1 if not */
int clear(struct List* lst) {
    if (lst==0) return -1;
    {
        struct Link* curr = lst->first;
        while (curr) {
            struct Link* next = curr->suc;
            free(curr);
            curr = next;
        }
        lst->first = lst->last = 0;
    }
    return 0;
}

/* free all elements of lst; then free lst; return 0 if okay, -1 if not */
int destroy(struct List* lst)
{
    if (lst==0) return -1;
    clear(lst);
    free(lst);
    return 0;
}

/* add p at end of lst; return 0 if okay, -1 if not */
int push_back(struct List* lst, struct Link* p)
{
    if (lst==0) return -1;
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
    return 0;
}

/* add p at front of lst; return 0 if okay, -1 if not */
int push_front(struct List* lst, struct Link* p)
{
    if (lst==0) return -1;
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
    return 0;
}

/* insert q before p in lst; return 0 if okay, -1 if not */
int insert(struct List* lst, struct Link* p, struct Link* q)
{
    if (lst==0) return -1;
    if (q==0) return 0; /* insert nothing */

    if (p == lst->first)    /* works also for empty list */
        push_front(lst,q);  /* q becomes new first element */
    else {
        q->suc = p;
        q->pre = p->pre;
        p->pre->suc = q;
        p->pre = q;
    }
    return 0;
}

/* remove p from lst; return a pointer to the link after p if ok, ERROR_PTR if
   not */
struct Link* erase(struct List* lst, struct Link* p)
{
    if (lst==0) return (struct Link*)ERROR_PTR;
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

/* return link n "hops" before or after p if ok, ERROR_PTR if not */
struct Link* advance(struct Link* p, int n)
{
    if (p==0) return ERROR_PTR;
    if (n > 0) {
        while (n--) {
            if (!p->suc)
                return ERROR_PTR;
            p = p->suc;
        }
        return p;
    }
    else if (n < 0) {
        while (n++) {
            if (!p->pre)
                return ERROR_PTR;
            p = p->pre;
        }
        return p;
    }
    else return p;  /* n == 0 */
}

/* convenience functions for Name Links */

int push_back_name(struct List* lst, char* n)   /* push back name */
{
    return push_back(lst,(struct Link*)make_name(n));
}

int push_front_name(struct List* lst, char* n)  /* push front name */
{
    return push_front(lst,(struct Link*)make_name(n));
}

int insert_name(struct List* lst, struct Link* p, char* n)  /* insert name */
{
    return insert(lst,p,(struct Link*)make_name(n));
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
    push_back_name(names,"Norah");
    push_back_name(names,"Annemarie");
    push_back_name(names,"Kris");
    print_lst(names);

    printf("\nErasing second name:\n");
    erase(names,advance(names->first,1));
    print_lst(names);

    printf("\nPushing front one name:\n");
    push_front_name(names,"Bjarne");
    print_lst(names);

    printf("\nInsert names at front and before last element:\n");
    insert_name(names,names->first,"Herbert");
    insert_name(names,names->last,"Scott");
    print_lst(names);

    printf("\nErasing first element until list empty:\n");
    while (erase(names,names->first));
    print_lst(names);

    printf("\nInserting one element so we have something to destroy:\n");
    insert_name(names,names->first,"Andrei");
    print_lst(names);

    printf("\nDestroying list\n\n");
    destroy(names);

    /* test error handling */
    {
        int err_code = init(0);
        struct Link* err_ptr = erase(0,0);
        if (err_code==-1) printf("error in init()\n");
        names = create();
        err_code = push_front_name(0,"Bjarne");
        if (err_code==-1) printf("error in push_front()\n");
        err_code = push_front_name(names,"Bjarne");
        if (err_code==-1) printf("error in push_front()\n");    /* OK */
        if (err_ptr==ERROR_PTR) printf("error in erase()\n");
        err_ptr = erase(names,names->first);
        if (err_ptr==ERROR_PTR) printf("error in erase()\n"); /* OK */
        err_code = clear(0);
        if (err_code==-1) printf("error in clear()\n");
        err_code = clear(names);
        if (err_code==-1) printf("error in clear()\n");
        err_code = destroy(0);
        if (err_code==-1) printf("error in destroy()\n");
        err_code = destroy(names);
        if (err_code==-1) printf("error in destroy()\n");
    }
}
