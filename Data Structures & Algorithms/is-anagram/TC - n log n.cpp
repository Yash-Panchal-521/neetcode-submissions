class Solution {
public:
    bool isAnagram(string s, string t) {

        // Sorting string
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Length validation
        if(s.length() != t.length()) {
            return false;
        }
        
        // Checking character one by one
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
