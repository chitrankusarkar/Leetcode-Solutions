class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        if(low == high)
            return nums[low];
        if(nums[low] <= nums[high])
            return nums[low];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return nums[mid];
            if(nums[0] <= nums[mid])
                low = mid + 1;
            if(nums[mid] <= nums[n - 1])
                high = mid - 1;
        }
        return -1;
    }
};
