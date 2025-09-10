class Solution {
    void helper(int currVal, int n, int k, vector<int>& temp, vector<vector<int>>& res) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if(currVal > n)
            return;
        temp.push_back(currVal);
        helper(currVal + 1, n, k, temp, res);
        temp.pop_back();
        helper(currVal + 1, n, k, temp, res);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(1, n, k, temp, res);
        return res;
    }
};
