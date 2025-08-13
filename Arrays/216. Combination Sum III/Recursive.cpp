class Solution {
    void helper(int idx, int sum, int n, int k, vector<int> &path, vector<vector<int>> &res) {
        if(sum == n && k == 0) {
            res.push_back(path);
            return;
        }
        if(sum > n)
            return;
        
        for(int i = idx; i <= 9; i++) {
            if(i > n)
                break;
            path.push_back(i);
            helper(i + 1, sum + i, n, k - 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helper(1, 0, n, k, path, res);
        return res;
    }
};
