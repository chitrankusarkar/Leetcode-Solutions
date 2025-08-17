class Solution {
  public:
    int helper(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp) {
        if(n == 0 || W == 0) // until bag weight is zero or done with all items
            return 0;
        if(dp[n][W] != -1) // check on the dp table, if value exists return from here
            return dp[n][W];
        if(wt[n - 1] <= W) {
            return dp[n][W] = max(val[n - 1] + helper(wt, val, W - wt[n - 1], n - 1, dp), // pick and decrease bag weight then check for prev element
                                 helper(wt, val, W, n - 1, dp)); // don't pick check for prev element
        }
        else
            return dp[n][W] = helper(wt, val, W, n - 1, dp);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int> (W + 1, - 1)); // n + 1 row, w + 1 column set with -1 initially
        int res = helper(wt, val, W, n, dp);
        return res;
    }
};
