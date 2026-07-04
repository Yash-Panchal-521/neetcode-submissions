class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Build a max heap: heapify every non-leaf node, bottom-up.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Repeatedly move the current max (root) to the end, then
        // re-heapify the shrinking heap.
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }

        return nums;
    }

private:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest]) largest = left;
        if (right < n && nums[right] > nums[largest]) largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};
