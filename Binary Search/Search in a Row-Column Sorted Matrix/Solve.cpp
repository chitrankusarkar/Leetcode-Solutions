class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = n - 1;
        while(i >= 0 && i < m && j >= 0 && j < n) {
            if(mat[i][j] == x)
                return true;
            else if(mat[i][j] > x)
                j--;
            else
                i++;
        }
        return false;
    }
};
