class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Insertion sort
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int min = INT_MAX;
            int min_idx = -1;
            for(int j = i; j < n; j++) {
                if(nums[j] < min) {
                    min = nums[j];
                    min_idx = j;
                }
            }
            swap(nums[i], nums[min_idx]);
        }

        return nums;
    }
};