class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";
        for(char c: s) {
            if(c == '(' && cnt++ > 0)
                res += c;
            if(c == ')' && cnt-- > 1)
                res += c;
        }
        return res;
    }
};

/*
dry run for input: "(()())(())"
Step 1: First '(' → depth goes from 0 to 1 → outermost → skip.
Step 2: Second '(' → depth goes from 1 to 2 → inner → keep '('.
Step 3: Next ')' → depth goes from 2 to 1 → inner → keep ')'.
Step 4: Next '(' → depth goes from 1 to 2 → inner → keep '('.
Step 5: Next ')' → depth goes from 2 to 1 → inner → keep ')'.
Step 6: Next ')' → depth goes from 1 to 0 → outermost → skip.
Step 7–10: Process second primitive "(())" in the same way, 
keeping only the inner pair.

Final output after skipping outermost pairs: "()()"
*/
