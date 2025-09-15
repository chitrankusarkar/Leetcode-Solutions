class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());
        text += ' ';
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < text.size(); i++) {
            if(st.find(text[i]) != st.end()) {
                while(text[i] != ' ') {
                    i++;
                }
                flag = true;
            }
            if(text[i] == ' ') {
                if(!flag)
                    cnt++;
                flag = false;
            }
        }
        return cnt;
    }
};
