class Solution {
    void helper(int idx, int sum, int target, vector<int> &temp, vector<int>& candidates, vector<vector<int>> &res) {
        if(target == sum) {
            res.push_back(temp);
            return;
        }
        if(idx >= candidates.size() || sum > target)
            return;
        temp.push_back(candidates[idx]);
        helper(idx, sum + candidates[idx], target, temp, candidates, res);
        temp.pop_back();
        helper(idx + 1, sum, target, temp, candidates, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(0, 0, target, temp, candidates, res);
        return res;
    }
};
