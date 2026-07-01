class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (auto num : nums) {
            mp[num]++;
        }

        for(auto pair: mp) {
            if(pair.second > n / 2) {
                return pair.first;
            }
        }
        // return -1;
    }
};