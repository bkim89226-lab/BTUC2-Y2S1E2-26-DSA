#include <iostream>
using namespace std;

typedef string Elem; // element type

class CNode {       // circularly linked list node
private:
    Elem elem;               // linked list element value
    CNode* next;             // next item in the list
    friend class CircleList; // provide CircleList access
};

class CircleList {  // a circularly linked list
public:
    CircleList();   // constructor
    ~CircleList();  // destructor
    bool empty() const;         // is list empty?
    const Elem& front() const;  // element at cursor
    const Elem& back() const;   // element following cursor
    void advance();             // advance cursor
    void add(const Elem& e);    // add after cursor
    void remove();              // remove node after cursor
    void printList() const;
private:
    CNode* cursor; // the cursor
};


// constructor
CircleList::CircleList() : cursor(NULL) { }  
// destructor
CircleList::~CircleList() { while (!empty()) remove(); } 
// is list empty?
bool CircleList::empty() const  { return cursor == NULL; }  
// element at cursor
const Elem& CircleList::back() const  { return cursor->elem; } 
// element following cursor
const Elem& CircleList::front() const { return cursor->next->elem; } 
// advance cursor
void CircleList::advance()  { cursor = cursor->next; }    


// add after cursor
void CircleList::add(const Elem& e) { 
    CNode* v = new CNode; // create a new node
    v->elem = e;
    if (cursor == NULL) { // list is empty?
        v->next = v;    // v points to itself
        cursor = v;     // cursor points to v
    }
    else {  // list is nonempty?
        v->next = cursor->next; // link in v after cursor
        cursor->next = v;
    }
}

// remove node after cursor
void CircleList::remove() { 
    CNode* old = cursor->next; // the node being removed
    if (old == cursor) // removing the only node?
        cursor = NULL; // list is now empty
    else
        cursor->next = old->next; // link out the old node
    delete old; // delete the old node
}


// print all elements
void CircleList::printList() const {

    // Check if the list is empty
    if (empty()) {
        cout << "[ ]" << endl;
        return;
    }

    // Start at the front node
    CNode* current = cursor->next;

    //cout << "[ -> ";

    // Continue until we come back to the front node
    do {
        cout << current->elem;

        // Mark the cursor
        if (current == cursor) {
            cout << " <- (Playing) ";
        }

        cout << "\n";

        current = current->next;

    } while (current != cursor->next);

    //cout << "]" << endl;
    cout << endl;
}


int main(){

    CircleList PlayList;

    PlayList.add("At Last by Etta James");
    PlayList.add("Unchained Melody by The Righteous Brothers");
    PlayList.add("Make You Feel My Love by Adele");

    PlayList.printList();
    PlayList.advance();
    cout << "\n";
    PlayList.printList();


}