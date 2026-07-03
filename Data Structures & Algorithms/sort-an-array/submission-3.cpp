class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Insertion sort
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;

            // Shift elements greater than key one position to the right
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }

            // Insert the key into its correct position
            nums[j + 1] = key;
        }

        return nums;
    }
};