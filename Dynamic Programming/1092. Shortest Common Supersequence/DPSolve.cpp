class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string res = "";
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = m, j = n;
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) {
                    res.push_back(str1[i - 1]);
                    i--;
                }
                else {
                    res.push_back(str2[j - 1]);
                    j--;
                }
            }
        }
        while(i > 0) {
            res.push_back(str1[i - 1]);
            i--;
        }
        while(j > 0) {
            res.push_back(str2[j - 1]);
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
