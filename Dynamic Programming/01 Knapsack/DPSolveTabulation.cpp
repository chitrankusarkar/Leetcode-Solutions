class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        int dp[n + 1][W + 1];
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < W + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0; // Initialization to base case
            }
        }
        
        for(int i = 1; i <= n; i++) { // start loop from 1 to access [i - 1] from start so, [0] would be accessed otherwise [-1] leads to seg. fault
            for(int j = 1; j <= W; j++) {
                if(wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]); // shift n->i & W->j from the recursive code
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
        
    }
};
