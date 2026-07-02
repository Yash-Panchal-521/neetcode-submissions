class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto num : nums) {
            mp[num]++;
        }
        vector<pair<int,int>> f(mp.begin(), mp.end());
        sort(f.begin(), f.end(),
             [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

        auto pt = f.begin();
        vector<int> ans;

        while (k != 0) {
            ans.push_back(pt->first);
            pt++;
            k--;
        }

        return ans;
    }
};
