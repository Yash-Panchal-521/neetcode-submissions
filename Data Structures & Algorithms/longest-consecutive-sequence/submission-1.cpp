class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }

        int cnt = 1, longest = INT_MIN;
        for (auto i : s) {
            auto prev = s.find(i - 1);
            if (prev != s.end()) {
                continue;
            } else {
                cnt = 1;
                auto nxt = i;
                while (s.find(nxt + 1) != s.end()) {
                    nxt = nxt + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
