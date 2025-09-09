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
            if(arr.get(mid) == target)
                return mid;
            else if(arr.get(mid) < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
    int binarySearchDescending(int target, MountainArray &arr, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr.get(mid) == target)
                return mid;
            else if(arr.get(mid) < target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
    int findPeakElement(MountainArray &arr) {
        int low = 0, high = arr.length() - 1, n = arr.length();
        while(low <= high) {
            int mid = low + (high - low) / 2;
                if(arr.get(mid) > arr.get(mid + 1) && arr.get(mid) > arr.get(mid - 1))
                    return mid;
                else if(arr.get(mid + 1) > arr.get(mid))
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
