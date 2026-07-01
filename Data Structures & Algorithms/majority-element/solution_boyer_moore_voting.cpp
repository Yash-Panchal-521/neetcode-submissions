class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cand,count = 0;

        for(auto num: nums) {
            if(count == 0) {
                cand = num;
            }

            if(num == cand) {
                count++;
            } else {
                count--;
            }
        }

        return cand;
    }
};