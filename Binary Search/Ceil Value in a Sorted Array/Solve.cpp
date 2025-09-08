class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1, res = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] >= x) {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};
