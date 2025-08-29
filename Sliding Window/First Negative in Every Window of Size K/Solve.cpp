class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> res;
        int i = 0, j = 0;
        queue<int> temp;
        while(j < arr.size()) {
            if(arr[j] < 0)
                temp.push(arr[j]);
            if(j - i + 1 < k) 
                j++;
            else if(j - i + 1 == k){
                if(temp.size() == 0) {
                    res.push_back(0);
                }
                else {
                    res.push_back(temp.front());
                    if(arr[i] == temp.front()) 
                        temp.pop();
                }
                i++;
                j++;
            }
        }
        return res;
    }
};
