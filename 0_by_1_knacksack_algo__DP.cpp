#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zero_by_1_knapsack(vector<int> weight, vector<int> profit, int m, int n) {

    int k[n + 1][m + 1];

    for(int i = 0 ; i <= n ; i++) {
        for(int w = 0 ; w <= m ; w++) {
            if(i == 0 || w == 0) {
                k[i][w] = 0;
            }
            else if(weight[i - 1] <= w) {
                k[i][w] = max( k[i - 1][w] ,  k[i-1][w - weight[i - 1]] + profit[i - 1] );
            }
            else {
                k[i][w] = k[i - 1][w];
            }
        }
    }
   

    int selected[n] = {0}; 
    int i = n, w = m;

    cout << "\nSelected items: \n";
    while (i > 0 && w > 0) {
         if (k[i][w] != k[i - 1][w]) {
             selected[i - 1] = 1; 
            w = w - weight[i - 1]; 
          } 
          else {
             selected[i - 1] = 0; 
         }
         i--;   
    }

        for (int index = 0; index < n; index++) {
             cout << "Item " << (index + 1) << " = " << selected[index] << endl; 
        }

         return  k[n][m];
}


int main(){
int w, p;
int m , n;

cout << "Capacity : Objects :: ";
cin >> m >> n;

vector<int> weight(n);
cout << "\nEnter the element of weight: ";
for(int i = 0 ; i < n ; i++) {
    cin >> weight[i];
}
    
vector<int> profit(n);
cout << "\nEnter the element of profit: ";
for(int i = 0 ; i < n ; i++) {
    cin >> profit[i];
}

int sum = zero_by_1_knapsack(weight, profit, m, n);
cout << "\nTotal profit is: " << sum;
 
}


/*
Capacity : Objects ::  8 4

Enter the element of weight:  3 4 6 5

Enter the element of profit: 2 3 1 4

Selected items:
Item 1 = 1
Item 2 = 0
Item 3 = 0
Item 4 = 1

Total profit is: 6


*/