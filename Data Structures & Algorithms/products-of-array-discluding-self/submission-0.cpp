class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_idx = -1, n = nums.size(), fact = 1;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num == 0) {
                if (zero_idx == -1) {
                    zero_idx = i;
                } else {
                    return ans;
                }
            } else {
                fact *= num;
            }
        }

        if (zero_idx != -1) {
            ans[zero_idx] = fact;
            return ans;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = fact / nums[i];
        }
        return ans;
    }
};
