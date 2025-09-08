class Solution {
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        if(low == high)
            return low;
        if(nums[low] <= nums[high])
            return low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return mid;
            if(nums[0] <= nums[mid])
                low = mid + 1;
            if(nums[mid] <= nums[n - 1])
                high = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mini = findMin(nums);
        int possibilityOne = binarySearch(nums, 0, mini - 1, target);
        int possibilityTwo = binarySearch(nums, mini, n - 1, target);
        if(possibilityOne != -1)
            return possibilityOne;
        if(possibilityTwo != -1)
            return possibilityTwo;
        return -1;
    }
};
