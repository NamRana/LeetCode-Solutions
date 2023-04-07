class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        
        for (int i = 0; i < n; ++i) {
            // the least number of Global inversion this number make.
            int x = (int) abs(nums[i] - i); 
            
            // To make sure that there is one global that is not local at the same time
            if(x > 1) return false;  // Condition fails
        }
        return true;
    }
};