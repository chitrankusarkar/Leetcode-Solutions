class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0, k = 0; i < n; i++) {
            if(arr[i] > arr[(i + 1) % n] && ++k > 1) {
              return false;
            }
        }
        return true;
    }
};
