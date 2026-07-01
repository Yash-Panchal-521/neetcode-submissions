class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int k = 0;
        int j = nums.size() - 1;

        while (nums[j] == val && j > 0) {
            j--;
        }

        for (int i = 0; i < j; i++) {

            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                do {
                    j--;
                } while (nums[j] == val && j > 0);
            }
        }

        for(auto num: nums) {
            if(num != val) k++;
        }

        return k;
    }
};