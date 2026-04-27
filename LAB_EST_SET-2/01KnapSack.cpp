#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            
            dp[i][w] = dp[i-1][w];
        
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W = 4;
    vector<int> val = {1, 2, 3};
    vector<int> wt  = {4, 5, 1};
    cout << "Maximum Value: " << knapsack(W, val, wt) << endl; // Output: 3
    return 0;
}
