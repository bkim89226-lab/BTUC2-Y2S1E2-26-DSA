#include <iostream>
using namespace std;

// Factorial function using Loop (iteration)
// n! =  n*(n-1)*(n-2)* .. *1

// using Loop
int factorialLoop(int n){
    if (n<=0) return 1;
    else{
        int t=1;
        for (int i =1; i<= n ; i++){
            t = t*i;
        }
        return t;
    }
}

// using recursion
// n! = f(n)   = n (n-1)! = n*f(n-1) 
int factorialRecursion(int n){
    // base case 
    cout << "running recursion" << endl;
    if (n==0) return 1;
    else return n*factorialRecursion(n-1);
}

int sumArray(int* A, int n){
    // base case 
    if (n==1) return A[0];
    else return sumArray(A, n-1) + A[n-1];
}


int main(){

    int Score[5] = {33, 45, 55, 66 , 77};
    int n = 5;
    int sum = sumArray(Score, n);
    cout << sum << endl;
    

    int result = factorialLoop(10);
    cout << result << endl;

    int result2 = factorialRecursion(10);
    cout << result2 << endl;
    return 0;
}