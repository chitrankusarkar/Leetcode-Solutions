class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxToLeft(n);
        vector<int> maxToRight(n);
        vector<int> temp(n);
        int res = 0;
        maxToLeft[0] = height[0];
        maxToRight[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++)
            maxToLeft[i] = max(maxToLeft[i - 1], height[i]);
        for(int i = n - 2; i >= 0; i--)
            maxToRight[i] = max(maxToRight[i + 1], height[i]);
        for(int i = 0; i < n; i++)
            temp[i] = min(maxToRight[i], maxToLeft[i]) - height[i];
        for(int i = 0; i < n; i++)
            res += temp[i];

        return res;
    }
};
