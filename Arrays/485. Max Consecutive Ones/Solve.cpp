class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cntOnes = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                cntOnes++;
                maxi = max(maxi, cntOnes);
            }
            else
                cntOnes = 0;
        }
        return maxi;
    }
};
