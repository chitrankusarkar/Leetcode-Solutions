class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currCount = 0, lastSmaller = INT_MIN, longest = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 0)
            return 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 == lastSmaller) {
                currCount++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                currCount = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, currCount);
        }
        return longest;
    }
};
