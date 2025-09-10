class Solution {
    bool isValid(vector<int> &arr, int n, int k, int mx) {
        int students = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum > mx) {
                students++;
                sum = arr[i];
            }
        }
        if(students > k)
            return false;
        return true;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int start = 0, end = 0, n = arr.size(), res = -1;
        if(n < k)
            return -1;
        for(auto it: arr) {
            end += it;
            if(it > start)
                start = it;
        }
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isValid(arr, n, k, mid)) {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return res;
    }
};
