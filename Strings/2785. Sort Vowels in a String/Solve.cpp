class Solution {
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
  public:
    string sortVowels(string s) {
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) 
                temp += s[i];
        }
        sort(temp.begin(), temp.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};
