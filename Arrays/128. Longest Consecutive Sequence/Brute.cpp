class Solution {
public:
    bool linearSearch(vector<int>& nums, int element) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == element)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n == 0)
            return 0;
        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            int cnt = 1;
            while(linearSearch(nums, ele + 1) == true) {
                ele++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
