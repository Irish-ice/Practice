#include <iostream>
#include <vector>
using namespace std;


int maximum_coins_in_limited_supply(vector<int>& coins, vector<int>& supply, int amount){
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for(int i = 0 ; i <= n ; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= amount ; j++) {
            dp[i][j] = dp[i - 1][j];

            for(int k = 1 ; k <= supply[i - 1]; k++) {
                if(j >= k * coins[i - 1]) {
                    dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
                }  
                else {
                    break;
                }          }
        }
    }
    return dp[n][amount];
}


int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    vector<int> coins(n);
    cout << "Enter the coins: ";
    for(int i = 0 ; i < n ; i++) {
        cin >> coins[i];
    }
    vector<int> supply(n);
    cout << "Enter the supply of coins: ";
    for(int i = 0 ; i < n ; i++) {
        cin >> supply[i];
    }

    int ways = maximum_coins_in_limited_supply(coins, supply, amount);
    cout << "The maximum coins in limited supply is: " << ways;

    return 0;

}

/*
Example:

Enter the size : 3
Enter the amount: 4
Enter the coins: 1 2 3
Enter the supply of coins: 3 2 1
The maximum coins in limited supply is: 3

*/
