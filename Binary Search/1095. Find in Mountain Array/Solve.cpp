/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int binarySearchAscending(int target, MountainArray &arr, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = arr.get(mid);
            if(midVal == target)
                return mid;
            else if(midVal < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
    int binarySearchDescending(int target, MountainArray &arr, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = arr.get(mid);
            if(midVal == target)
                return mid;
            else if(midVal < target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
// reduced .get() API calls by storing left and right values early
// If mid == 0, there’s no arr[mid-1]. So I set it to INT_MIN, which ensures index 0 can still be considered a peak if it’s bigger than arr[1].
// If mid == n-1, there’s no arr[mid+1]. So I set it to INT_MIN, which ensures the last index can be a peak if it’s bigger than arr[n-2].
    int findPeakElement(MountainArray &arr) {
        int low = 0, high = arr.length() - 1, n = arr.length();
        while(low <= high) {
            int mid = low + (high - low) / 2;
                int midVal = arr.get(mid);
                int leftVal = mid > 0 ? arr.get(mid - 1) : INT_MIN;
                int rightVal = mid < n - 1 ? arr.get(mid + 1) : INT_MIN;
                if(midVal > leftVal && midVal > rightVal)
                    return mid;
                else if(rightVal > midVal)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int peak = findPeakElement(arr);
        int leftHalf = binarySearchAscending(target, arr, 0, peak - 1);
        int rightHalf = binarySearchDescending(target, arr, peak, n - 1);
        if(leftHalf != -1)
            return leftHalf;
        if(rightHalf != -1)
            return rightHalf;
        return -1;
    }
};
