class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int i = 0, j = 0, mx = INT_MIN;
        while(j < nums.size()) {
            int x = nums[j];
            if(j - i + 1 < k)
                j++;
            else if(j - i + 1 == k) {
                mx = INT_MIN;
                for(int l = i; l <= j; l++)
                    mx = max(mx, nums[l]);
                res.push_back(mx);
                i++;
                j++;
            }
        }
        return res;
    }
};
