class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivotIdx = partition(nums, low, high);
        quickSort(nums, low, pivotIdx - 1);
        quickSort(nums, pivotIdx + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        // Randomize the pivot choice so a sorted/reverse-sorted input
        // doesn't degrade to the O(n^2) worst case.
        int randIdx = low + rand() % (high - low + 1);
        swap(nums[randIdx], nums[high]);

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};
