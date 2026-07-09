class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto e : nums) {
            if (e > 0) mp[e]++;
        }
        int i = 1;
        while (true) {
            if (mp[i] != 0) {
                i++;
            } else { 
                break;
            }
        }
        return i;
    }
};