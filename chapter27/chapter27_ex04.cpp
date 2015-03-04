// Chapter 27, exercise 4: write C++ version of intrusive List in 27.9

// could be optimized: reuse parts of insert for push_back, for example, or make
// Link an abstract base class

#include<iostream>
#include<string>

using namespace std;

//------------------------------------------------------------------------------

struct Link {
    Link() :next(0), prev(0) { }
    Link* next;
    Link* prev;
    virtual void print(ostream& os) const { };
};

//------------------------------------------------------------------------------

Link* advance(Link* p, int n)
{
    if (p==0) return 0;
    if (n==0) return p;
    if (n > 0) {
        while (n--) {
            if (p->next->next)  // peek past tail
                p = p->next;
            else
                return 0;
        }
        return p;
    }
    if (n < 0) {
        while (n++) {
            if (p->prev)
                p = p->prev;
            else
                return 0;
        }
        return p;
    }
}

//------------------------------------------------------------------------------

class Name : public Link {
public:
    Name() :Link(), the_name() { };
    Name(string s) :Link(), the_name(s) { }
    string name() const { return the_name; }
    void print(ostream& os) const { os << the_name; }
private:
    string the_name;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Link& l)
{
    l.print(os);
    return os;
}

//------------------------------------------------------------------------------

class List {
public:
    List() :head(0), tail(0) { }
    ~List();

    Link* begin() const { return head; }
    Link* end() const { return tail; }

    void push_back(Link* p);
    void push_front(Link* p);
    void insert(Link* p, Link* q);  // insert q before p
    Link* erase(Link* p);   // erase p, return pointer to successor
private:
    Link* head;
    Link* tail; // one past the last element
};

//------------------------------------------------------------------------------

List::~List()
{
    Link* p = head;
    while (p != tail) {
        Link* q = p->next;
        delete(p);
        p = q;
    }
}

//------------------------------------------------------------------------------

void List::push_back(Link* p)
{
    if (p==0) return;
    if (head == 0) {
        head = p;
        p->prev = 0;
        tail = new Link();
    }
    else {
        p->prev = tail->prev;
        tail->prev->next = p;
    }
    tail->prev = p;
    p->next = tail;
}

//------------------------------------------------------------------------------

void List::push_front(Link* p)
{
    if (p==0) return;
    if (head == 0) {
        tail = new Link();
        p->next = tail;
        tail->prev = p;
    }
    else {
        head->prev = p;
        p->next = head;
    }
    head = p;
    p->prev = 0;
}

//------------------------------------------------------------------------------

// insert q before p
void List::insert(Link* p, Link* q)
{
    if (p==0 || q==0) return;
    if (p == head) {
        head = q;
        q->prev = 0;
    }
    else {
        p->prev->next = q;
        q->prev = p->prev;
    }
    q->next = p;
    p->prev = q;
}

//------------------------------------------------------------------------------

// erase p, return pointer to successor
Link* List::erase(Link* p)
{
    if (p==0) return 0;
    if (p==head && p->next==tail) { // list becomes empty
        head = 0;
        tail = 0;
        delete(p);
        return 0;
    }
    if (p == head) {
        head = p->next;
        p->next->prev = 0;
    }
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    Link* q = p->next;
    delete(p);
    return q;
}

//------------------------------------------------------------------------------

void print(const List& l)
{
    for (Link* p = l.begin(); p!=l.end(); p=p->next)
        cout << *p << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    // test push_back, push_front
    cout << "push_back Benjamin, push_front Kara:\n";
    List the_list;
    the_list.push_back(new Name("Benjamin"));
    the_list.push_front(new Name("Kara"));
    print(the_list);

    // test insert
    cout << "\ninsert Chico at front, Fipsli at end, Bjarne before Fipsli:\n";
    the_list.insert(the_list.begin(),new Name("Chico"));
    Name* n = new Name("Fipsli");
    the_list.insert(the_list.end(),n);
    the_list.insert(n,new Name("Bjarne"));
    print(the_list);

    // test advance
    Link* l = the_list.begin();
    l = ::advance(l,3);
    cout << "\nbegin(), advance by 3: " << *l << '\n';
    l = ::advance(l,-1);
    cout << "and advanced by -1: " << *l << '\n';

    // erase last element
    l = ::advance(the_list.end(),-1);
    l = the_list.erase(l);
    cout << '\n';
    print(the_list);

    // erase first element
    l = the_list.erase(the_list.begin());
    cout << '\n';
    print(the_list);

    // erase element in the middle
    the_list.erase(::advance(l,1));
    cout << '\n';
    print(the_list);

    // erase all elements
    l = the_list.begin();
    while (l != the_list.end()) {
        l = the_list.erase(l);
        cout << '\n';
        print(the_list);
    }
}
