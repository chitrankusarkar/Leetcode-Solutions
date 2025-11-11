class Solution {
    int dp[101][101][601];
    int solve(vector<pair<int, int>>& count, int m , int n, int idx) {
        if(idx >= count.size() || (m == 0 && n == 0))
            return 0;
        
        if(dp[m][n][idx] != -1)
            return dp[m][n][idx];

        int pick = 0, skip = 0;

        if(count[idx].first <= m && count[idx].second <= n) 
            pick = 1 + solve(count, m - count[idx].first, n - count[idx].second, idx + 1);
        skip = solve(count, m, n, idx + 1);
        return dp[m][n][idx] = max(pick, skip);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int, int>> count(N);
        for(int i = 0; i < N; i++) {
            int zeroCnt = 0, oneCnt = 0;
            for(auto it: strs[i]) {
                if(it == '0')
                    zeroCnt++;
                else    
                    oneCnt++;
            }
            count[i] = {zeroCnt, oneCnt};
        }
        memset(dp, -1, sizeof(dp));
        return solve(count, m, n, 0);
    }
};
