class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Stores: number -> index

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i]; // Required complement

            // If complement exists, we've found the pair
            if (mp.find(comp) != mp.end()) {
                return {mp[comp], i};
            }

            // Store current number and its index
            mp[nums[i]] = i;
        }

        // No valid pair found (guaranteed not needed for this problem)
        return {};
    }
};