#include <iostream>
using namespace std;

// sort an array of n characters
void insertionSort(int *A, int n)  {
    // insertion loop
    for (int i = 1; i < n; i++) {                    
        int cur = A[i]; // current character to insert
        int j = i - 1;   // start at previous character
        // while A[j] is out of order
        while ((j >= 0) && (A[j] > cur)) {                    
            A[j + 1] = A[j]; // move A[j] right
            j--;             // decrement j
        }
        A[j + 1] = cur; // this is the proper place for cur
    }
}
// Run time O(n^2)   -> slow 


int main() {

    int Score[10] = {33, 22, 11, 66, 55, 33, 66, 77, 88, 99};

    cout << endl;
    for (int i= 0 ; i< 10; i++){
        cout << Score[i] << "   " ;
    }
    cout << endl;

    insertionSort(Score, 10);
    cout << endl;
    for (int i= 0 ; i< 10; i++){
        cout << Score[i] << "   " ;
    }


}