#include <iostream>
#include <string>
using namespace std;

// test 2
// test 3
// test 4

class GameEntry
{ // a game score entry
public:
    GameEntry(const string &n = "", int s = 0); // constructor
    string getName() const;                     // get player name
    int getScore() const;                       // get score
private:
    string name; // player’s name
    int score;   // player’s score
};

class Scores
{ // stores game high scores
public:
    Scores(int maxEnt = 10);      // constructor
    ~Scores();                    // destructor
    void add(const GameEntry &e); // add a game entry
    GameEntry remove(int i);      // remove the ith entry
    void printList() const;
private:
    int maxEntries;     // maximum number of entries
    int numEntries;     // actual number of entries
    GameEntry *entries; // array of game entries
};

int main()
{
    GameEntry P1("Mike", 1105);
    GameEntry P2("Rob", 750);
    GameEntry P3("Paul", 720);
    GameEntry P4("Anna", 660);
    GameEntry P5("Rose", 590);
    GameEntry P6("Jack", 510);

    Scores ScoreBoard(10);

    ScoreBoard.add(P4);
    ScoreBoard.add(P5);
    ScoreBoard.add(P6);
    ScoreBoard.add(P1);
    ScoreBoard.add(P2);
    ScoreBoard.add(P3);

    ScoreBoard.printList();

    ScoreBoard.remove(1);
    ScoreBoard.printList();

}

// Constructor
GameEntry::GameEntry(const string &n, int s)
    : name(n), score(s) {}

// Accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

Scores::Scores(int maxEnt)
{                                        // constructor
    maxEntries = maxEnt;                 // save the max size
    entries = new GameEntry[maxEntries]; // allocate array storage
    numEntries = 0;                      // initially no elements
}
Scores::~Scores()
{ // destructor
    delete[] entries;
}

void Scores::add(const GameEntry &e)
{                                // add a game entry
    int newScore = e.getScore(); // score to add
    if (numEntries == maxEntries)
    { // the array is full
        if (newScore <= entries[maxEntries - 1].getScore())
            return; // not high enough - ignore
    }
    else
        numEntries++; // if not full, one more entry

    int i = numEntries - 2; // start with the next to last
    while (i >= 0 && newScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i]; // shift right if smaller
        i--;
    }
    entries[i + 1] = e; // put e in the empty spot
}

GameEntry Scores::remove(int i)
{
    if ((i < 0) || (i >= numEntries)) // invalid index
        throw "Invalid index";

    GameEntry e = entries[i]; // save the removed object

    for (int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j]; // shift entries left
    numEntries--;                    // one fewer entry
    return e;                        // return the removed object
}


void Scores::printList() const {
    for (int i = 0; i < numEntries; i++){
        cout << i+1 << ": " << entries[i].getName() << " : " << entries[i].getScore() << endl;
    }

}


