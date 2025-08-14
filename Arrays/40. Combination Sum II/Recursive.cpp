class Solution {
    void helper(int idx, int sum, int target, vector<int>& candidates, vector<int> &temp, vector<vector<int>> &res) {
        if(sum == target) {
            res.push_back(temp);
            return;
        }
        if(idx >= candidates.size() || sum > target)
            return;
        temp.push_back(candidates[idx]);
        helper(idx + 1, sum + candidates[idx], target, candidates, temp, res);
        temp.pop_back();
        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1])
            idx++;
        helper(idx + 1, sum, target, candidates, temp, res);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        helper(0, 0, target, candidates, temp, res);
        return res;
    }
};
