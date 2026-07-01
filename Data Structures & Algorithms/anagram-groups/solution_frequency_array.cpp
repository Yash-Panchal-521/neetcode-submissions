class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        while (strs.size() != 0) {
            string curr = strs[0];

            vector<string> sim_to_curr;
            sim_to_curr.push_back(curr);

            int i = 1;
            while (i < strs.size()) {
                if (strs[i].length() != curr.length()) {
                    i++;
                    continue;
                }

                vector<int> count(26);
                bool is_anagram = true;

                for (int j = 0; j < curr.length(); j++) {
                    count[curr[j] - 'a']++;
                    count[strs[i][j] - 'a']--;
                }

                for (auto c : count) {
                    if (c != 0) {
                        is_anagram = false;
                        break;
                    }
                }

                if (is_anagram) {
                    sim_to_curr.push_back(strs[i]);
                    strs.erase(strs.begin() + i);
                } else {
                    i++;
                }
            }
            strs.erase(strs.begin());
            ans.push_back(sim_to_curr);
        }
        return ans;
    }
};
