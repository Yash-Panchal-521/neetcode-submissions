class Solution {
   public:
    bool isPalindrome(string s) {
        string st = "";

        for (auto ch : s) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                st += tolower(ch);
        }

        int n = st.size();
        for (int i = 0; i < n / 2; i++) {
            if (st[i] != st[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
