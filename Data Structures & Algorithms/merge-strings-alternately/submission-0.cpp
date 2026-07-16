class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i = 0, j = 0, n = word1.length(), m = word2.length();

        while (i < n || j < m) {
            if (i != n) {
                s += word1[i++];
            }
            if (j != m) {
                s += word2[j++];
            }
        }

        return s;
    }
};