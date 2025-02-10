class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char i : s) {
            if(isdigit(i)) {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(i);
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
