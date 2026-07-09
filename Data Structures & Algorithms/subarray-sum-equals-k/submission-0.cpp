class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        mp[sum] = 1;
        for(auto e: nums) {
            sum += e;
            int find = sum - k;
            if(mp.find(find) != mp.end()) {
                ans += mp[find];
            }
            mp[sum]++;
        }

        return ans;
    }
};