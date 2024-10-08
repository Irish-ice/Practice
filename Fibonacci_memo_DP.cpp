

//fibonacci series using dynamic programming by using memoization
//also known as top-down approach

#include <iostream>
#include <vector>
using namespace std;

static int count = 0;
int memo[100];

int fibonacci(int n){
    

    if(memo[n] != -1 ) return memo[n];
    count++;

    if( n == 0 ) return memo[n] = 0;
    
    if( n == 1) return memo[n] = 1;

    else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

void sum_of_fibonacci(int  n){
    for(int i = 0 ; i <= n  ; i++){
       fibonacci(i);
    }
}

int main() {
    int n;
    cout << "Enter an Input: ";
    cin >> n;

    

    for(int i  =  0 ; i < 100 ; i++) {
        memo[i] = -1;
    }

    sum_of_fibonacci(n);
    cout << "The fibonacci series is: " ;
    for(int i = 0 ; i < n ; i++) {
        cout << memo[i] << " " ;
    }

    cout << "\nNumber of recursion happened: " << count;
}

/*
Enter an Input: 7
The fibonacci series is: 0 1 1 2 3 5 8 
Number of recursion happened: 8
*/