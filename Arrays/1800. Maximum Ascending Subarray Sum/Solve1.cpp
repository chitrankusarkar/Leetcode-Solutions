class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], maxSum = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i - 1]) {
                maxSum = max(maxSum, sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(maxSum, sum);
    }
};
