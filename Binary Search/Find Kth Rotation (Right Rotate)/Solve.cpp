class Solution {
public:
    int findKRotation(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the last element,
            // the pivot (minimum) must be in the right half.
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // If mid element is less than or equal to the last element,
            // the pivot could be mid or in the left half.
            else {
                high = mid;
            }
        }
        
        // after loop ends low and high will point to the minimum element.
        return high;
    }
};
