class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        /* int lcsLen = dp[m][n];
        int delCount = m - lcsLen;
        int insCount = n - lcsLen;
        
        int res = delCount + insCount;
        return res;
        */
        return (m - dp[m][n] + n - dp[m][n]);
    }
};
