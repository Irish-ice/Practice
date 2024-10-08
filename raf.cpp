#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of ways to make the amount with limited supply of coins
int ways_of_coin_change(const vector<int>& coins, const vector<int>& supply, int amount) {
    int n = coins.size();
    // DP table where dp[i][j] is the number of ways to make amount j using the first i coins
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    
    // Base case: There's one way to make amount 0 (by using no coins)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            // First, inherit the value from the previous row (not using the current coin)
            dp[i][j] = dp[i - 1][j];
            
            // Now consider using the current coin with its supply limit
            for (int k = 1; k <= supply[i - 1]; k++) {
                if (j >= k * coins[i - 1]) {
                    dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
                } else {
                    break;
                }
            }
        }
    }

    return dp[n][amount];
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int n;
    cout << "Enter the number of different coin types: ";
    cin >> n;

    vector<int> coins(n), supply(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the supply limit for each coin: ";
    for (int i = 0; i < n; i++) {
        cin >> supply[i];
    }

    int result = ways_of_coin_change(coins, supply, amount);
    cout << "Number of ways to make the given amount: " << result << endl;

    return 0;
}
