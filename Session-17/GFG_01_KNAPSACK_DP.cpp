class Solution {
public:

    // int solve(int i, int W, vector<int> &val, vector<int> &wt, 
    //           int curr, vector<vector<int>>& dp) {

    //     if(i >= wt.size() || curr >= W) return 0;

    //     if(dp[i][curr] != -1) return dp[i][curr];

    //     int pick = 0;
    //     if(curr + wt[i] <= W) {
    //         pick = val[i] + solve(i+1, W, val, wt, curr + wt[i], dp);
    //     }

    //     int notpick = solve(i+1, W, val, wt, curr, dp);

    //     return dp[i][curr] = max(pick, notpick);
    // }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        vector<int>prev(W+1,0);
        vector<int>current(W+1,0);
        
        for(int i = 1; i <= n; i++){
            for(int curr = 0; curr <= W; curr++){

                if(wt[i-1] <= curr){
                    // current[curr]=max(prev[curr],val[i-1]+prev[curr-wt[i-1]]);
                    dp[i][curr] = max(dp[i-1][curr],val[i-1] + dp[i-1][curr - wt[i-1]]);
                }
                else{
                    dp[i][curr] = dp[i-1][curr];
                    // currrent[curr] = prev[curr];
                }
                // prev = current;
            }
        }
        // prev[W];
        return dp[n][W]; 
    }
};
