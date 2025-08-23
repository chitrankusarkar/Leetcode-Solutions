class Solution {
    static int dp[1001][1001];
    int helper(string& text1, string& text2, int n, int m) {
        if(n == 0 || m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(text1[n - 1] == text2[m - 1])
            return dp[n][m] = 1 + helper(text1, text2, n - 1, m - 1);
        else
            return dp[n][m] = max(helper(text1, text2, n, m - 1), helper(text1, text2, n - 1, m));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memset(dp, - 1, sizeof(dp));
        int res = helper(text1, text2, n, m);
        return res;
    }
};
int Solution::dp[1001][1001];
