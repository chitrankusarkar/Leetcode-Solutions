class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid - 1] == target)
                return mid - 1;
            if(arr[mid + 1] == target)
                return mid + 1;
            else if(arr[mid] < target)
                low = mid + 2;
            else
                high = mid - 2;
        }
        return -1;
    }
};
