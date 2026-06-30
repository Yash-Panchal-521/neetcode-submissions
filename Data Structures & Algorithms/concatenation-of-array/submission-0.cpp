class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector<int> arr(2*n);

        for(int i = 0; i < n; i++) {
            // The below code is wrong, it inserts new element instead modifying.
            // Expected Output: [1,4,1,2,1,4,1,2]
            // Below code Output: [1,4,1,2,0,0,0,2,1,4,1,0,0,0,0,0]
            // arr.insert(arr.begin() + i, nums[i]);
            // arr.insert(arr.begin() + n + i, nums[i]);
            
            // Correct solution. Because we already initalized 2*n arr with '0' as elements
            arr[i] = nums[i];
            arr[i+n] = nums[i];

        }

        return arr;
        
    }
};