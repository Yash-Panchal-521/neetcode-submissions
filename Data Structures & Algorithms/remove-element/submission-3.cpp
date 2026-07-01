class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; 

        for(auto num: nums) {
            if(num != val) {
                nums[k++] = num;
            }
        }

        return k;
    }
};