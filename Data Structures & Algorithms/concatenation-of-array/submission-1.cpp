class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        // Alternative approach: using vector's insert func

        vector<int> arr = nums;
        arr.insert(arr.begin(), nums.begin(), nums.end());
        return arr;
        
    }
};