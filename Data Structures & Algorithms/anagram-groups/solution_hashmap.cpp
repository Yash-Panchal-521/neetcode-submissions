class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(auto str: strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto p: mp) {
            ans.push_back(p.second);
        }

        return ans;
        
    }
};
