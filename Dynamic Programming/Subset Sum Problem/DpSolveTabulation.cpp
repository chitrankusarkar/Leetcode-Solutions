class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int dp[n + 1][sum + 1];
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) { // initialization
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(arr[i - 1] <= j) { // same like knapsack considering arr as weight array and sum as knapsack capacity
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // replace n->i, sum->j
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};
