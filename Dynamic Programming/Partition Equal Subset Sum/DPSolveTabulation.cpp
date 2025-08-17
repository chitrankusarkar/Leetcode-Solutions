class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i < n; i++)
            sum += arr[i];
        if(sum % 2 != 0) // say sum is 23, can never equally partition, say 22 can do 11 and 11 partition
            return false;
        int target = 0;
        if(sum % 2 == 0)
            target = sum / 2; 
        int dp[n + 1][target + 1];
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < target + 1; j++) {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) { 
                if(arr[i - 1] <= j) { // no need to check other half, if it has valid partition and we took the half to work on other half automatically covered
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // n->i, sum(target)->j
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};
