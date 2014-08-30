// Chapter 18 exercise 11: implement a skip list. Following Ottmann & Widmayer,
// "Algorithmen and Datenstrukturen" (3rd Edition), 1997, Chapter 1.7.1

#include "../lib_files/std_lib_facilities.h"

struct element {
    element(int k, int new_height) : key(k), next(new_height+1) { }
    int key;
    vector<element*> next;
};

class skip_list {
public:
    skip_list();
    element* find(int x);
    void insert(int x);
    void remove(int x);
    void print();
    void debug_print();
    int get_height() { return height; }
private:
    const int max_height = 16;
    const int infty = numeric_limits<int>::max();
    element head;
    element tail;
    int height;
    int random_height();
};

// initialise empty list with head element's next pointing to tail element
// on all list levels
skip_list::skip_list()
    :head(0,max_height), tail(infty,0), height(0)
{
    for (int i = 0; i<head.next.size(); ++i)
        head.next[i] = &tail;
}

// returns pointer to element with key x if x exists in list, 0 otherwise
element* skip_list::find(int x) {
    element* p = &head;

    for (int i = height; i>=0; --i) {
        while (p->next[i]->key < x) {
            p = p->next[i];
        }
    }

    // now either p == &head and x <= p->next[0]->key
    // or p != &head and p->key < x <= p->next[0]->key
    p = p->next[0];
    if (p->key == x) return p;  // x is at position p in list
    else return 0;              // x is not in list
}

// inserts element with key x into list
void skip_list::insert(int x) {
    vector<element*> update(max_height+1);
    element* p = &head;

    for (int i = height; i>=0; --i) {
        while (p->next[i]->key < x) {
            p = p->next[i];
        }
        update[i] = p;
    }
    p = p->next[0];

    if (p->key == x) return;    // key x exists already in list

    int new_height = random_height();
    if (new_height > height) {  // link new element to head, adjust list height
        for (int i = height+1; i<=new_height; ++i) {
            update[i] = &head;
        }
        height = new_height;
    }

    // create new element with height new_height and key x
    p = new element(x,new_height);

    // insert p into level i lists immediately after element update[i]
    for (int i = 0; i<=new_height; ++i) {
        p->next[i] = update[i]->next[i];
        update[i]->next[i] = p;
    }
}

// removes element with key x from list
void skip_list::remove(int x) {
    vector<element*> update(max_height+1);
    element* p = &head;
    for (int i = height; i>=0; --i) {
        while (p->next[i]->key < x)
            p = p->next[i];
        update[i] = p;
    }
    p = p->next[0];

    // if found, remove and potentially reduce list height
    if (p->key == x) {
        for (int i = 0; i<p->next.size(); ++i) {
            // remove p from level i list
            update[i]->next[i] = p->next[i];
        }
        while (height>=1 && head.next[height]->key == infty)
            --height;
        delete p;
    }
}

void skip_list::print() {
    element* p = head.next[0];
    cout << "{";
    while (p->key != infty) {
        cout << ' ' << setw(2) << p->key;
        p = p->next[0];
    }
    cout << " }" << "\n";
}

// print lists at higher levels
void skip_list::debug_print() {
    for (int i = 0; i<=height; ++i) {
        element* p = head.next[0];
        cout << "Lvl " << i << ": {";
        while (p->key != infty) {
            if (p->next.size() > i)
                cout << ' ' << setw(2) << p->key;
            else
                cout << "   ";
            p = p->next[0];
        }
        cout << " }" << "\n";
    }
}

int skip_list::random_height() {
    int rand_height = 0;
    while (randint(10000)<5000 && rand_height<max_height)
        ++rand_height;
    return rand_height;
}

int main()
try {
    srand(time(0));
    const int test_val = 75;
    while (true) {
        skip_list sl;
        for (int i = 0; i<23; ++i)
            sl.insert(randint(100));
        sl.debug_print();
        cout << "Enter value to remove: ";
        int x;
        cin >> x;
        if (x==-1) return 0;

        element* p = sl.find(x);
        sl.remove(x);
        sl.debug_print();
        cout << "\n";
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
