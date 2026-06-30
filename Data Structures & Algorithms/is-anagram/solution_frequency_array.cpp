class Solution {
   public:
    bool isAnagram(string s, string t) {
         // Length Validation First 
        if (s.length() != t.length()) {
            return false;
        }

         // Array for keeping count for Letters  
        int count[26];

         // Adjusting frequency one by one character
        for (int i = 0; i < s.length(); i++) {
            // S string's character frequency would be increasing
            count[s[i] - 'a']++;
            // T string's character frequency would be decreasing to balance
            count[t[i] - 'a']--;
        }

         // At the end, check the counts array
        for(auto c: count) {
           // If any, not zero then not anagram (indicating excessive or less character in a specific string)
            if(c!=0) {
                return false;
            }
        }
        return true;
    }
};
