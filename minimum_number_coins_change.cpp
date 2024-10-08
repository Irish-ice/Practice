

#include <iostream>
#include <vector>
using namespace std;



int minimum_number_of_coins_change(const vector<int>& coins, int amount){
    int n = coins.size();

    vector<vector<int>> dp (n+1, vector<int>(amount+1, 0));

    for(int i = 0; i < n ; i++){
        dp[i][0] = 1;
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 1 ; j <= amount ; j++) {
            if(coins[i-1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = min( dp[i-1][j], 1+ dp[i][j - coins[j]] );
            }
        }
    }

    return dp[n][amount];

}

int main() {
    int n ;

    cout << "Enter the coins: ";
    cin >> n ;

    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    int amount ;
    cin >> amount;

    int result = minimum_number_of_coins_change(coins, amount);
    cout << "Minimum number of coins:  " << result;

}
