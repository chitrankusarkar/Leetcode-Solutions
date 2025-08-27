class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        int maxLen = 0, endPos = 0;
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    int l = dp[i][j];
                    int startInS = i - l;
                    int startInRev = n - j;
                    if (startInS == startInRev && l > maxLen) {
                        maxLen = l;
                        endPos = i;
                    }
                }
            }
        }

        return s.substr(endPos - maxLen, maxLen);
    }
};
