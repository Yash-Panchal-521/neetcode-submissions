class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, e1, e2, n = nums.size();
        for (auto e : nums) {
            if (c1 == 0) e1 = e;
            if (c2 == 0) e2 = e;

            if (e == e1)
                c1++;
            else if (e == e2)
                c2++;
            else {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;

        for (auto e : nums) {
            if (e == e1) c1++;
            if (e == e2) c2++;
        }

        vector<int> ans;
        if (c1 > (n / 3)) ans.push_back(e1);
        if (c2 > (n / 3) && e1 != e2) ans.push_back(e2);
        return ans;
    }
};