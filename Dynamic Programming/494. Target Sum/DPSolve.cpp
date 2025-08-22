class Solution {
    int countSubsetSumEqualsTarget(int n, vector<int>& nums, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < target + 1; j++) {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
            if(nums[i - 1] == 0)
                dp[i][0] = dp[i - 1][0] * 2;
            else
                dp[i][0] = dp[i - 1][0];
        }
        return dp[n][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums)
            sum += it;
        if(sum < abs(target) || (target + sum) % 2 != 0)
            return 0;
        int subsetSum = (target + sum) / 2;
        int res = countSubsetSumEqualsTarget(n, nums, subsetSum);
        return res;
    }
};
