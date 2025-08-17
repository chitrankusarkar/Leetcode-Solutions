class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mpp;
        for(int i = 1; i < n; i++) {
            sum = nums[i] + nums[i - 1];
            mpp[sum]++;
            if(mpp[sum] > 1)
                return true;
        }
        return false;
        
    }
};
