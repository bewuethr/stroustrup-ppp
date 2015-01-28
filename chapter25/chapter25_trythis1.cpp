// Chapter 25, Try This 1: demonstrate free store fragmentation... not much
// to be seen here!

#include<iostream>

using namespace std;

// type that requires a little more space than a Node
struct Message {
    int a;
    int b;
    int c;
};

// somewhat smaller type, but not half as small as a Message
struct Node {
    int a;
    int b;
};

void frag()
{
    Message* p = new Message();
    Node* n1 = new Node();
    delete p;
    Node* n2 = new Node();
    Message* pp = 0;
    Node* nn1 = 0;
    Node* nn2 = 0;
    for (int i = 0; i<100; ++i) {
        pp = new Message();
        nn1 = new Node();
        delete pp;
        nn2 = new Node();
    }
    cout << "Difference with fragmentation: " << nn2-n1 << '\n';
}

void non_frag()
{
    Node* n1 = new Node();
    Node* n2 = new Node();
    Message* p = new Message();
    delete p;
    Message* pp = 0;
    Node* nn1 = 0;
    Node* nn2 = 0;
    for (int i = 0; i<100; ++i) {
        nn1 = new Node();
        nn2 = new Node();
        pp = new Message();
        delete pp;
    }
    cout << "Difference without fragmentation: " << nn2-n1 << '\n';
}

int main()
{
    cout << "sizeof(Message): " << sizeof(Message) << '\n';
    cout << "sizeof(Node): " << sizeof(Node) << '\n';
    frag();
    non_frag();
}
