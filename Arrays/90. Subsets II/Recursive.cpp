class Solution {
    void helper(int idx, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>> &res) {
        if(idx >= n) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(idx + 1, n, nums, temp, res);
        temp.pop_back();
        while(idx + 1 < n && nums[idx] == nums[idx + 1])
            idx++;
        helper(idx + 1, n, nums, temp, res);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        helper(0, n, nums, temp, res);
        return res;
    }
};
