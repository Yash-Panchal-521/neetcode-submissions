class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto num : nums) {
            mp[num]++;
        }
        
        vector<vector<int>> bucket(nums.size()+1);

        for(auto pt = mp.begin(); pt != mp.end(); pt++) {
            bucket[pt->second].push_back(pt->first);
        }

        vector<int> ans;

        for(int j = bucket.size() - 1; j > 0 && ans.size() < k; j--) {
            vector<int> sub = bucket[j];
            for(auto num: sub) {
                if(ans.size() < k) {
                    ans.push_back(num);
                }
            } 
        }

        return ans;
    }
};
