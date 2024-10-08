#include <iostream>
#include <vector>
using namespace std;


int  ways_of_coin_change(vector<int> coin, int amount) {
    int i = 0, j = 0;
    int n = coin.size();

    vector<vector<int>>  a(n + 1, vector<int>(amount + 1, 0));

for (int i = 0; i <= n; i++) {
    a[i][0] = 1;  
}

    for(int i= 1  ; i <= n ; i++) {
        for(int  j = 1 ; j <= amount ; j++) {
            if(coin[i - 1] > j ) {
                a[i][j] = a[i - 1][j];
            }
            else {
                a[i][j] = a[i - 1][j] + a[i][j - coin[i - 1]];
            }
        }
    }

    return a[n][amount];
}


int main(){
    
    int amount;
    cout << "Enter the given amount: " ;
    cin >> amount;


    cout << "How many coins: ";
    int  n;
    cin >> n;
    vector<int> coin(n);
    cout << "Now input the denomination of coins: ";
    for(int i = 0 ; i < n ; i++) {
        cin >> coin[i];
    }

    int result = ways_of_coin_change(coin, amount);
    cout << "Number of ways to make the given amount is: " << result << endl;
}


/*
Enter the given amount: 15
How many coins: 4
Now input the denomination of coins: 2 3 5 10
Number of ways to make the given amount is: 9

*/

