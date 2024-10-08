//iterative ways to get fibonacci series
//also known as bottom-top approach or tabular technique



#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n){
    
    int  a[100];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2 ; i <= n ; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    return a[n];
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


    sum_of_fibonacci(n);
    cout << "The fibonacci series is: " ;
    for(int i = 0 ; i < n ; i++) {
        cout << fibonacci(i) << " " ;
    }
}

/*
Enter an Input: 7
The fibonacci series is: 0 1 1 2 3 5 8 
*/