//this problem is  for nth  number of  fibonacci number

#include <iostream>
#include <vector>
using namespace std;


//1
static int count = 0;

int fibonacci(int n){
    count++;
    if( n == 0 ) return 0;
    
    if( n == 1) return 1;

    else {
        int sum = fibonacci(n - 1) + fibonacci(n - 2);
        return sum;
    }

}

int main() {
    int n;
    cout << "Enter an Input: ";
    cin >> n;

    int total = fibonacci(n);
    cout << "Nth number element of the fibonacci series is: " << total <<  endl;
    cout << "Number of recursion happened: " << count;
}

/*
Enter an Input: 7
Nth number element of the fibonacci series is: 13
Number of recursion happened: 41
*/






//this problem is for the sum of  n number of element
//2

/*
static int count = 0;
int fibonacci(int n){
    count++;
    if( n == 0 ) return 0;
    
    if( n == 1) return 1;

    else {
        int sum = fibonacci(n - 1) + fibonacci(n - 2);
        return sum;
    }

}

int sum_of_fibonacci(int  n){
    int  sum = 0;
    for(int i = 0 ; i <= n  ; i++){
        sum += fibonacci(i);
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter an Input: ";
    cin >> n;

    int total = sum_of_fibonacci(n);
    cout << "Sum of the fibonacci series is: " << total <<  endl;
    cout << "Number of recursion happened: " << count;
}
*/


/*
Enter an Input: 7
Sum of the fibonacci series is: 33
Number of recursion happened: 100
*/






//print the fibonacci series
//3

/*
vector<int> series;
static int count = 0;

int fibonacci(int n){
    count++;
    if( n == 0 ) return 0;
    
    if( n == 1) return 1;

    else {
        int sum = fibonacci(n - 1) + fibonacci(n - 2);
        return sum;
    }

}

int sum_of_fibonacci(int  n){
    int  sum = 0;
    for(int i = 0 ; i <= n  ; i++){
        series.push_back(fibonacci(i)) ;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter an Input: ";
    cin >> n;

    sum_of_fibonacci(n);

    cout << "The fibonacci series is: " ;
    for(int i = 0 ; i < n ; i++) {
        cout << series[i] << " " ;
    }
}
*/


/*
Enter an Input: 7
The fibonacci series is: 0 1 1 2 3 5 8
*/




