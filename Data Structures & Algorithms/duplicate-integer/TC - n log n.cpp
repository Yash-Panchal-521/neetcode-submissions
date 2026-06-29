class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mp; 
        for(auto i: nums){
            if(mp[i] > 0) {
                return true;
            }
            else {
                mp[i]++;
            }
        }
        return false;
    }
};
