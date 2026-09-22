#include <iostream>
#include <map>
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
// n! = f(n) = n (n-1)! = n*f(n-1) 
int factorialRecursion(int n){
    // cout << "running recursion" << endl;
    // base case 
    if (n==0) return 1;
    else return n*factorialRecursion(n-1);
}

int sumArray(int* A, int n){
    // base case 
    if (n==1) return A[0];
    else return sumArray(A, n-1) + A[n-1];
}


long long Fib(int n){
    if (n <= 1){
        return n;
    }
    else {
        return Fib(n-1) + Fib(n-2);
    }
}
// Space ->  O(?)  -> Stack memory -> O(n)
// Runtime -> O(?)  -> O(2^n)   (Exact:  (1.618)^n)

map<int, long long> cache;
long long FibWithMemorization(int n){
    if (n <= 1){
        return n;
    }
    if (n <= cache.size()) return cache[n];
    else {
        cache[n] = FibWithMemorization(n-1) + FibWithMemorization(n-2);
        return cache[n];
    }
} // Runtime -> O(n) 


int main(){

    // int result = factorialLoop(10);
    // cout << result << endl;

    // int result2 = factorialRecursion(10);
    // cout << result2 << endl;

    // int Score[5] = {33, 45, 55, 66 , 77};
    // int n = 5;
    // int sum = sumArray(Score, n);
    // cout << sum << endl;

    // Long running code 
    // cout << Fib(50) << endl;

    // Fast running code 
    cout << FibWithMemorization(50) << endl;


    // map<int, int> m;
    // m[0] = 10;
    // m[1] = 20;
    // cout << m.size() << endl;


    return 0;
}