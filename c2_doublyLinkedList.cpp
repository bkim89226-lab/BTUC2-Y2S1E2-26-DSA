#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef string Elem; // list element type

// doubly linked list node
class DNode {
private:
    Elem elem;                // node element value
    DNode *prev;              // previous node in list
    DNode *next;              // next node in list
    friend class DLinkedList; // allow DLinkedList access
};

// doubly linked list
class DLinkedList {
public:
    DLinkedList();                // constructor
    ~DLinkedList();               // destructor
    bool empty() const;           // is list empty?
    const Elem &front() const;    // get front element
    const Elem &back() const;     // get back element
    void addFront(const Elem &e); // add to front of list
    void addBack(const Elem &e);  // add to back of list
    void removeFront();           // remove from front
    void removeBack();            // remove from back
    void printList() const;   // // print all elements

private:
    DNode *header;                // list sentinel
    DNode *trailer;               // list sentinel

protected:
    void add(DNode *v, const Elem &e); // insert new node before v
    void remove(DNode *v);             // remove node v
};


// constructor
DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;

    header->next = trailer;
    trailer->prev = header;
}

// destructor
DLinkedList::~DLinkedList() {
    while (!empty())
        removeFront();

    delete header;
    delete trailer;
}

// is the list empty
bool DLinkedList::empty() const {
    return (header->next == trailer);
}

// get front element
const Elem& DLinkedList::front() const {
    return header->next->elem;
}

// get back element
const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

// insert new node before v
void DLinkedList::add(DNode *v, const Elem &e) {
    DNode *u = new DNode;

    u->elem = e;
    u->next = v;
    u->prev = v->prev;

    v->prev->next = u;
    v->prev = u;
}

// add to front of list
void DLinkedList::addFront(const Elem &e) {
    add(header->next, e);
}

// add to back of list
void DLinkedList::addBack(const Elem &e) {
    add(trailer, e);
}

// remove node v
void DLinkedList::remove(DNode *v) {
    DNode *u = v->prev;
    DNode *w = v->next;

    u->next = w;
    w->prev = u;

    delete v;
}

// remove from front
void DLinkedList::removeFront() {
    remove(header->next);
}

// remove from back
void DLinkedList::removeBack() {
    remove(trailer->prev);
}

void DLinkedList::printList() const {
    DNode *current = header->next;
    cout << "[ ";
    while (current != trailer) {
        cout << current->elem ;
        current = current->next;
        if (current != trailer) { cout << " <--> ";}
    }
    cout << "]" << endl;
}

int main() {
    
    
    DLinkedList TravelStop;
    TravelStop.addFront("Toulouse");
    TravelStop.addFront("Frankfurt");
    TravelStop.addFront("Qatar");
    TravelStop.printList();
  
    TravelStop.addBack("Bacelona");
    TravelStop.printList();

    return 0;
}

