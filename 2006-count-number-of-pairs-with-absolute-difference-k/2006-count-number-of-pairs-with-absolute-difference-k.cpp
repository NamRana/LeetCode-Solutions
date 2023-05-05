class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int c=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                c+=(abs(nums[i]-nums[j]))==k;
            }
        }
        return c;
    }
};