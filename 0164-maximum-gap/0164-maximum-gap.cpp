class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;
        
        sort(nums.begin(),nums.end());
        int m=0;
        for(int i=0,j=1;i<n-1;i++,j++){
            m=max(m,nums[j]-nums[i]);
        }
        return m;
    }
};