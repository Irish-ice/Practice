#include <iostream>
#include <climits>
#include <vector>
using namespace std;


int min_number_of_coins_change(vector<int> coins, int amount) {
    int n = coins.size();
    vector<vector<int>> a (n + 1 ,vector<int>(amount + 1 , INT_MAX));

    for(int i = 0 ; i <= n ; i++) {
        a[i][0] = 0;
    }
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= amount ; j++) {
            if(coins[i - 1] > j) {
                a[i][j] = a[i -  1][j];
            }
            else {
                a[i][j] = min(a[i - 1][j], 1 + a[i][j - coins[i - 1]]);
            }
        }
    }
    

    int i = n, j = amount;
    cout << "\nSelected coins: \n";
    while(i > 0 && j >  0) {
        if(a[i][j] != a[i - 1][j]) {
            cout << coins[i - 1] << endl;
            j -= coins[i - 1];
        }
        else {
            i--;
        }
    }

    return a[n][amount];
}


int main() {

    int amount;
    cout << "Enter the given amount: " ;
    cin >> amount;

    cout << "How many coins: ";
    int  n;
    cin >> n;

    vector<int> coins(n);
    cout << "Now input the denomination of coins: ";
    for(int i = 0 ; i < n ; i++) {
        cin >> coins[i];
    }

    int result = min_number_of_coins_change(coins, amount);
    cout << "The minimum number of coin change is: "  << result << endl;
}

/*
Enter the given amount: 10
How many coins: 4
Now input the denomination of coins: 1 5 6 9
Selected coins:
5, 5
The minimum number of coin change is: 2
*/

