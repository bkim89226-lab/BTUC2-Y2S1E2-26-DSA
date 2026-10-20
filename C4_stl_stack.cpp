#include <iostream>
#include <stack>

using namespace std;
using std::stack, std::string;

int main(){

    stack<string> Book;

    Book.push("C program");
    Book.push("C++ essential");
    Book.push("Windows basic");

    cout << Book.top() << endl;

    while (!Book.empty()) {
        if (!Book.empty())
            {
            cout << Book.top() << endl;
            Book.pop();
        }
    }


}
